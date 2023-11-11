#ifndef FAZE_SCREEN_HPP
#define FAZE_SCREEN_HPP

#include <faze/define.hpp>

namespace fz
{
    class Screen
    {
    public:
        /**
         *
         */
        Screen();

        /**
         *
         */
        virtual ~Screen() = default;

        /**
         *
         */
        ma::u16
        index() const;

        /**
         *
         */
        ma::u16
        event() const;

        /**
         *
         */
        void
        set_index(ma::u16 index);

        /**
         *
         */
        void
        set_event(ma::u16 event);

        /**
         *
         */
        virtual void
        on_enter() {};

        /**
         *
         */
        virtual void
        on_leave() {};

        /**
         *
         */
        virtual bool
        on_handle(const sf::Event& event) = 0;

        /**
         *
         */
        virtual void
        on_update(float delta) = 0;

        /**
         *
         */
        virtual void
        on_render(sf::RenderTarget& target) = 0;

    private:
        /**
         *
         */
        ma::u16 m_index;

        /**
         *
         */
        ma::u16 m_event;
    };
} // namespace fz

#endif // FAZE_SCREEN_HPP
