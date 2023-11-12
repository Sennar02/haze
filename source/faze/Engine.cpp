#include <faze/Engine.hpp>
#include <faze/Screen.hpp>

#include <smal/Memory/import.hpp>
#include <smal/Parser/import.hpp>

namespace fz
{
    Engine::Engine(ma::BaseOrigin* origin, ma::usize size)
        : m_window {}
        , m_clock {}
        , m_active {true}
        , m_states {origin, size}
    { }

    bool
    Engine::is_active() const
    {
        return this->m_active;
    }

    void
    Engine::loop(ma::usize screen, ma::usize frames)
    {
        // Move "start", "frames" after resource management

        sf::Time  slice = sf::seconds(1.0f / frames);
        sf::Time  delta;
        sf::Event event;

        if ( this->m_states.launch(screen) == false )
            return;

        // Move after resource management
        this->m_window.create(win_vmode, win_title, win_style);

        while ( this->m_active ) {
            delta += this->m_clock.restart();

            while ( this->m_window.pollEvent(event) )
                this->handle(event);

            for ( ; delta < slice; delta -= slice )
                this->update(slice.asSeconds());

            this->render(this->m_window);
        }

        this->m_window.close();
    }

    StateMachine<Screen>&
    Engine::states()
    {
        return this->m_states;
    }

    const StateMachine<Screen>&
    Engine::states() const
    {
        return this->m_states;
    }

    void
    Engine::handle(const sf::Event& event)
    {
        Screen* active = this->m_states.active();
        ma::u32 next   = 0;

        if ( active != 0 ) {
            next = active->handle(event);

            if ( next != 0 )
                this->m_active = this->m_states.launch(next);
        } else
            this->m_active = false;
    }

    void
    Engine::update(float delta)
    {
        Screen* active = this->m_states.active();

        if ( active != 0 )
            active->update(delta);
    }

    void
    Engine::render(sf::RenderWindow& window)
    {
        Screen* active = this->m_states.active();

        // Move after resource management
        auto clear = sf::Color {255, 255, 255};

        window.clear(clear);

        if ( active != 0 )
            active->render(window);

        window.display();
    }
} // namespace fz
