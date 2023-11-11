#include <faze/ConfigScreen.hpp>
#include <faze/Engine.hpp>

namespace fz
{
    ConfigScreen::ConfigScreen()
        : Screen()
    { }

    void
    ConfigScreen::on_enter()
    { }

    void
    ConfigScreen::on_leave()
    { }

    bool
    ConfigScreen::on_handle(const sf::Event& event)
    {
        if ( event.type == sf::Event::Closed )
            return false;

        if ( event.type == sf::Event::KeyReleased ) {
            if ( event.key.code == sf::Keyboard::Escape )
                return false;
        }

        return true;
    }

    void
    ConfigScreen::on_update(float delta)
    { }

    void
    ConfigScreen::on_render(sf::RenderTarget& target)
    { }
} // namespace fz
