#ifndef FAZE_SCREEN_MACHINE_HPP
#define FAZE_SCREEN_MACHINE_HPP

#include <faze/Screen.hpp>

namespace fz
{
    class ScreenMachine
    {
    public:
        /**
         *
         */
        ScreenMachine(ma::BaseOrigin* origin, ma::usize size = 0);

        /**
         *
         */
        bool
        contains(Screen* screen) const;

        /**
         *
         */
        bool
        insert(Screen* screen);

        /**
         *
         */
        bool
        remove(Screen* screen);

        /**
         *
         */
        bool
        launch(ma::usize screen);

        /**
         *
         */
        bool
        change(ma::usize screen);

        /**
         *
         */
        bool
        handle(const sf::Event& event);

        /**
         *
         */
        void
        update(float delta);

        /**
         *
         */
        void
        render(sf::RenderTarget& target);

    private:
        /**
         *
         */
        ma::HashMap<ma::usize, Screen*> m_holder;

        /**
         *
         */
        Screen* m_screen;
    };
} // namespace fz

#endif // FAZE_SCREEN_MACHINE_HPP
