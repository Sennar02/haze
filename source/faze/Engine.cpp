#include <faze/Engine.hpp>
#include <faze/State.hpp>

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
    Engine::loop(ma::u16 index, ma::usize frames)
    {
        // Move "start", "frames" after resource management

        sf::Time  slice = sf::seconds(1.0f / frames);
        sf::Time  delta;
        sf::Event event;

        if ( this->m_states.launch(index, 0) == false )
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

        this->m_states.finish();
        this->m_window.close();
    }

    StateMachine<State>&
    Engine::states()
    {
        return this->m_states;
    }

    const StateMachine<State>&
    Engine::states() const
    {
        return this->m_states;
    }

    void
    Engine::handle(const sf::Event& event)
    {
        State*  active = this->m_states.active();
        ma::u16 family = 0;
        ma::u16 status = 0;

        if ( active != 0 ) {
            family = active->family();
            status = active->handle(event);

            if ( status != 0 )
                this->m_active = this->m_states.launch(
                    family, status);
        } else
            this->m_active = false;
    }

    void
    Engine::update(float delta)
    {
        State* active = this->m_states.active();

        if ( active != 0 )
            active->update(delta);
    }

    void
    Engine::render(sf::RenderWindow& window)
    {
        State* active = this->m_states.active();

        // Move after resource management
        auto clear = sf::Color {255, 255, 255};

        window.clear(clear);

        if ( active != 0 )
            active->render(window);

        window.display();
    }
} // namespace fz
