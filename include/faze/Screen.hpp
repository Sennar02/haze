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
        bool
        isActive() const;

        /**
         *
         */
        bool
        setNext(String next);

        /**
         *
         */
        String
        next();

        /**
         *
         */
        virtual void
        enter();

        /**
         *
         */
        virtual void
        leave();

        /**
         *
         */
        virtual bool
        attach();

        /**
         *
         */
        virtual bool
        detach();

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

    protected:
        /**
         *
         */
        String m_next;
    };
} // namespace fz

#endif // FAZE_SCREEN_HPP
