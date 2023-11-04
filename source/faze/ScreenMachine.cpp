#include <faze/ScreenMachine.hpp>

namespace fz
{
    ScreenMachine::ScreenMachine(ma::BaseOrigin* origin, ma::usize size)
        : m_holder {origin, size}
        , m_screen {0}
    { }

    bool
    ScreenMachine::contains(const ScreenChange& change) const
    {
        return this->m_holder.contains(change.index());
    }

    bool
    ScreenMachine::insert(const ScreenChange& change, Screen* screen)
    {
        if ( change.index() != 0 )
            return this->m_holder.insert(change.index(), screen);

        return false;
    }

    bool
    ScreenMachine::remove(const ScreenChange& change)
    {
        return this->m_holder.remove(change.index());
    }

    bool
    ScreenMachine::launch(Screen* screen)
    {
        if ( screen != 0 ) {
            this->m_screen = screen;

            this->m_screen->startup();
            return true;
        }

        return false;
    }

    bool
    ScreenMachine::handle(const sf::Event& event)
    {
        ScreenChange change;

        if ( this->m_screen == 0 ) return false;

        if ( this->m_screen->handle(event) == false ) {
            change = {
                this->m_screen->code(),
                this->m_screen->next(),
            };

            this->m_screen->cleanup();

            if ( this->m_holder.contains(change.index()) ) {
                this->m_screen = this->m_holder[change.index()];

                this->m_screen->startup();
                return true;
            }
        } else
            return true;

        return false;
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
