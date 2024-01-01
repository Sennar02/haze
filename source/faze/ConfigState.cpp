#include <faze/ConfigState.hpp>
#include <faze/Engine.hpp>

namespace fz
{
    ConfigState::ConfigState()
        : State(States::Config)
    { }

    void
    ConfigState::enter()
    {
        printf("<config-enter>\n");
    }

    void
    ConfigState::leave()
    {
        printf("<config-leave>\n");
    }

    bool
    ConfigState::attach()
    {
        printf("<config-attach>\n");

        return true;
    }

    void
    ConfigState::detach()
    {
        printf("<config-detach>\n");
    }

    ma::u16
    ConfigState::handle(const sf::Event& event)
    {
        if ( event.type == sf::Event::Closed )
            return this->status();

        if ( event.type == sf::Event::KeyReleased ) {
            if ( event.key.code == sf::Keyboard::Escape )
                return this->status();
        }

        return 0;
    }

    void
    ConfigState::update(float delta)
    { }

    void
    ConfigState::render(sf::RenderTarget& target)
    { }
} // namespace fz
