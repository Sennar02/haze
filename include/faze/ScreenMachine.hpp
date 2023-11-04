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
        contains(const ScreenChange& change) const;

        /**
         *
         */
        bool
        insert(const ScreenChange& change, Screen* screen);

        /**
         *
         */
        bool
        remove(const ScreenChange& change);

        /**
         *
         */
        bool
        launch(Screen* screen);

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
        ma::HashMap<ma::u32, Screen*> m_holder;

        /**
         *
         */
        Screen* m_screen;
    };
} // namespace fz

#endif // FAZE_SCREEN_MACHINE_HPP
