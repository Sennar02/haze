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
        ma::usize
        code() const;

        /**
         *
         */
        ma::usize
        next() const;

        /**
         *
         */
        void
        set_code(ma::usize code);

        /**
         *
         */
        void
        set_next(ma::usize next);

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
        ma::usize m_code;

        /**
         *
         */
        ma::usize m_next;
    };
} // namespace fz

#endif // FAZE_SCREEN_HPP
