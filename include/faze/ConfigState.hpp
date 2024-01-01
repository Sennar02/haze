#ifndef FAZE_CONFIG_SCREEN_HPP
#define FAZE_CONFIG_SCREEN_HPP

#include <faze/State.hpp>

namespace fz
{
    class ConfigState
        : public State
    {
    public:
        ConfigState();

        void
        enter();

        void
        leave();

        bool
        attach();

        void
        detach();

        ma::u16
        handle(const sf::Event& event);

        void
        update(float delta);

        void
        render(sf::RenderTarget& target);
    };
} // namespace fz

#endif // FAZE_CONFIG_SCREEN_HPP
