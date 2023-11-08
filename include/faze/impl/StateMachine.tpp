#include <faze/StateMachine.hpp>

namespace fz
{
    template <class State>
    StateMachine<State>::StateMachine(ma::BaseOrigin* origin, ma::usize size)
        : m_holder {origin, size}
        , m_active {0}
    { }

    template <class State>
    bool
    StateMachine<State>::contains(ma::usize index) const
    {
        return this->m_holder.contains(index);
    }

    template <class State>
    bool
    StateMachine<State>::insert(ma::usize index, State* state)
    {
        if ( state == 0 || index == 0 )
            return false;

        state->set_code(index);

        return this->m_holder
            .insert(index, state);
    }

    template <class State>
    bool
    StateMachine<State>::remove(ma::usize index)
    {
        return this->m_holder.remove(index);
    }

    template <class State>
    bool
    StateMachine<State>::launch(ma::usize index)
    {
        if ( this->m_active != 0 )
            this->m_active->on_leave();

        if ( this->m_holder.contains(index) == true ) {
            this->m_active = this->m_holder[index];
            this->m_active->on_enter();
        } else
            this->m_active = 0;

        return this->m_active != 0;
    }

    template <class State>
    State*
    StateMachine<State>::active()
    {
        return this->m_active;
    }

    template <class State>
    const State*
    StateMachine<State>::active() const
    {
        return this->m_active;
    }
} // namespace fz
