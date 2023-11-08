#ifndef FAZE_STATE_MACHINE_HPP
#define FAZE_STATE_MACHINE_HPP

#include <faze/Screen.hpp>

namespace fz
{
    template <class State>
    class StateMachine
    {
    public:
        /**
         *
         */
        StateMachine(ma::BaseOrigin* origin, ma::usize size = 0);

        /**
         *
         */
        bool
        contains(ma::usize index) const;

        /**
         *
         */
        bool
        insert(ma::usize index, State* state);

        /**
         *
         */
        bool
        remove(ma::usize index);

        /**
         *
         */
        bool
        launch(ma::usize index);

        /**
         *
         */
        State*
        active();

        /**
         *
         */
        const State*
        active() const;

    private:
        /**
         *
         */
        ma::HashMap<ma::usize, State*> m_holder;

        /**
         *
         */
        State* m_active;
    };
} // namespace fz

#include <faze/impl/StateMachine.tpp>

#endif // FAZE_STATE_MACHINE_HPP
