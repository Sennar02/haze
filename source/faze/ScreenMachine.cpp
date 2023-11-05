#include <faze/ScreenMachine.hpp>

namespace fz
{
    ScreenMachine::ScreenMachine(ma::BaseOrigin* origin, ma::usize size)
        : m_holder {origin, size}
        , m_screen {0}
    { }

    bool
    ScreenMachine::contains(Screen* screen) const
    {
        if ( screen != 0 )
            return this->m_holder.contains(screen->self());

        return false;
    }

    bool
    ScreenMachine::insert(Screen* screen)
    {
        if ( screen != 0 && screen->self() != 0 )
            return this->m_holder.insert(screen->self(), screen);

        return false;
    }

    bool
    ScreenMachine::remove(Screen* screen)
    {
        if ( screen != 0 )
            return this->m_holder.remove(screen->self());

        return false;
    }

    bool
    ScreenMachine::launch(ma::usize screen)
    {
        if ( this->m_holder.contains(screen) == true ) {
            this->m_screen = this->m_holder[screen];
            this->m_screen->startup();

            return true;
        }

        return false;
    }

    bool
    ScreenMachine::change(ma::usize screen)
    {
        this->m_screen->cleanup();

        if ( this->m_holder.contains(screen) == true ) {
            this->m_screen = this->m_holder[screen];
            this->m_screen->startup();

            return true;
        }

        return false;
    }

    bool
    ScreenMachine::handle(const sf::Event& event)
    {
        ma::usize next = 0;

        if ( this->m_screen->handle(event) == true )
            return true;

        next = this->m_screen->next();

        return this->change(next);
    }

    void
    ScreenMachine::update(float delta)
    {
        this->m_screen->update(delta);
    }

    void
    ScreenMachine::render(sf::RenderTarget& target)
    {
        this->m_screen->render(target);
    }
} // namespace fz
