#ifndef FAZE_STATE_HPP
#define FAZE_STATE_HPP

#include <faze/define.hpp>

namespace fz
{
    class State
    {
    public:
        /**
         *
         */
        State(ma::u16 family);

        /**
         *
         */
        virtual ~State() = default;

        /**
         *
         */
        ma::u16
        status() const;

        /**
         *
         */
        void
        set_status(ma::u16 status);

        /**
         *
         */
        ma::u16
        family() const;

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
        virtual bool
        attach()
        {
            return true;
        }

        /**
         *
         */
        virtual void
        detach() {};

        /**
         *
         */
        virtual ma::u16
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
        ma::u16 m_family;

        /**
         *
         */
        ma::u16 m_status;
    };

    struct StateFamily
    {
    private:
        inline static ma::u16 s_count = 0;

    public:
        template <class State>
        inline static const ma::u16 of =
            s_count++;
    };
} // namespace fz

#endif // FAZE_STATE_HPP
