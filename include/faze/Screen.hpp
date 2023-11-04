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
        Screen(ma::u16 code);

        /**
         *
         */
        virtual ~Screen() = default;

        /**
         *
         */
        ma::u16
        code() const;

        /**
         *
         */
        ma::u16
        next() const;

        /**
         *
         */
        void
        set_next(ma::u16 code);

        /**
         *
         */
        virtual void
        startup() = 0;

        /**
         *
         */
        virtual void
        cleanup() = 0;

        /**
         *
         */
        virtual bool
        handle(const sf::Event& event) = 0;

        /**
         *
         */
        virtual void
        update(float delta) = 0;

        /**
         *
         */
        virtual void
        render(sf::RenderTarget& target) = 0;

    private:
        /**
         *
         */
        ma::u16 m_code;

        /**
         *
         */
        ma::u16 m_next;
    };

    union ScreenChange
    {
    public:
        /**
         *
         */
        ScreenChange();

        /**
         *
         */
        ScreenChange(Screen& curr, Screen& next);

        /**
         *
         */
        ScreenChange(ma::u16 curr, ma::u16 next);

        /**
         *
         */
        ma::u32
        index() const;

    private:
        struct
        {
            /**
             *
             */
            ma::u16 m_curr;

            /**
             *
             */
            ma::u16 m_next;
        };

        /**
         *
         */
        ma::u32 m_index;
    };
} // namespace fz

#endif // FAZE_SCREEN_HPP
