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
        Screen(ma::usize index);

        /**
         *
         */
        virtual ~Screen() = default;

        /**
         *
         */
        ma::usize
        self() const;

        /**
         *
         */
        ma::usize
        next() const;

        /**
         *
         */
        void
        set_next(ma::usize index);

        /**
         *
         */
        virtual void
        startup() {};

        /**
         *
         */
        virtual void
        cleanup() {};

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
        ma::usize m_self;

        /**
         *
         */
        ma::usize m_next;
    };
} // namespace fz

#endif // FAZE_SCREEN_HPP
