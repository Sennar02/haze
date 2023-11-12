#ifndef FAZE_STATE_MACHINE_HPP
#define FAZE_STATE_MACHINE_HPP

#include <faze/Screen.hpp>

namespace fz
{
    template <class State>
    class StateMachine
        : public ma::HashMap<ma::u32, State*>
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
        insert(ma::u32 index, State* state);

        /**
         *
         */
        bool
        launch(ma::u32 index);

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
        State* m_active;
    };
} // namespace fz

#include <faze/impl/StateMachine.tpp>

#endif // FAZE_STATE_MACHINE_HPP
