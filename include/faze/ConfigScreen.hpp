#ifndef FAZE_CONFIG_SCREEN_HPP
#define FAZE_CONFIG_SCREEN_HPP

#include <faze/Screen.hpp>

namespace fz
{
    class ConfigScreen
        : public Screen
    {
    public:
        ConfigScreen();

        void
        on_enter();

        void
        on_leave();

        bool
        on_handle(const sf::Event& event);

        void
        on_update(float delta);

        void
        on_render(sf::RenderTarget& target);
    };
} // namespace fz

#endif // FAZE_CONFIG_SCREEN_HPP
