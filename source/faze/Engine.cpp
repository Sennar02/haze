#include <faze/Engine.hpp>

namespace fz
{
    Engine::Engine(ma::u32 size)
        : ScreenManager(size)
        , m_active {true}
        , m_window {}
        , m_clock {}
    { }

    bool
    Engine::isActive() const
    {
        return m_active;
    }

    bool
    Engine::loop(String name, ma::u32 frames)
    {
        // Move "start", "frames" after resource management

        sf::Time  slice = sf::seconds(1.0f / frames);
        sf::Time  delta;
        sf::Event event;

        if ( launch(name) == false ) return false;

        // Move after resource management
        m_window.create(win_vmode, win_title, win_style);
        m_window.clear();

        while ( m_active ) {
            delta += m_clock.restart();

            while ( m_window.pollEvent(event) )
                handle(event);

            if ( m_active ) {
                for ( ; slice < delta; delta -= slice )
                    update(slice);

                render();
            } else
                break;
        }

        m_window.close();

        return true;
    }

    void
    Engine::handle(const sf::Event& event)
    {
        Screen* screen = active();

        if ( screen != 0 ) {
            if ( screen->handle(event) == false )
                m_active = launch(screen->next());
        } else
            m_active = false;
    }

    void
    Engine::update(const sf::Time& delta)
    {
        active()->update(delta.asSeconds());
    }

    void
    Engine::render()
    {
        m_window.display();
        m_window.clear();

        active()->render(m_window);
    }
} // namespace fz
