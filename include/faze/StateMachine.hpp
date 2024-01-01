#ifndef FAZE_STATE_MACHINE_HPP
#define FAZE_STATE_MACHINE_HPP

#include <faze/define.hpp>
#include <faze/StateTransit.hpp>

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
        contains(ma::u16 index, ma::u16 event) const;

        /**
         *
         */
        bool
        insert(const StateTransit& transit, State* state);

        /**
         *
         */
        bool
        remove(ma::u16 index, ma::u16 event);

        /**
         *
         */
        bool
        launch(ma::u16 index, ma::u16 event);

        /**
         *
         */
        bool
        finish();

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
        ma::HashMap<ma::u32, State*> m_holder;

        /**
         *
         */
        State* m_active;
    };
} // namespace fz

#include <faze/impl/StateMachine.tpp>

#endif // FAZE_STATE_MACHINE_HPP
