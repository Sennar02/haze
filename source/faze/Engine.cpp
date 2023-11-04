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
    Engine::loop(Screen* start, ma::usize frames)
    {
        // Move "start", "frames" after resource management

        sf::Time  slice = sf::seconds(1.0f / frames);
        sf::Time  delta;
        sf::Event event;

        if ( this->m_states.launch(start) == false )
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
    }

    ScreenMachine&
    Engine::states()
    {
        return this->m_states;
    }

    const ScreenMachine&
    Engine::states() const
    {
        return this->m_states;
    }

    void
    Engine::handle(const sf::Event& event)
    {
        this->m_active = this->m_states.handle(event);
    }

    void
    Engine::update(float delta)
    {
        this->m_states.update(delta);
    }

    void
    Engine::render(sf::RenderWindow& window)
    {
        // Move after resource management
        auto clear = sf::Color {255, 255, 255};

        window.clear(clear);

        this->m_states.render(window);

        window.display();
    }
} // namespace fz
