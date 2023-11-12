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
        ma::u32
        code() const;

        /**
         *
         */
        ma::u32
        next() const;

        /**
         *
         */
        void
        set_code(ma::u32 code);

        /**
         *
         */
        void
        set_next(ma::u32 next);

        /**
         *
         */
        virtual void
        enter() {};

        /**
         *
         */
        virtual void
        leave() {};

        /**
         *
         */
        virtual ma::u32
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
        ma::u32 m_code;

        /**
         *
         */
        ma::u32 m_next;
    };
} // namespace fz

#endif // FAZE_SCREEN_HPP
