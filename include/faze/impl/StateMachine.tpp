#include <faze/StateMachine.hpp>

namespace fz
{
    template <class State>
    StateMachine<State>::StateMachine(ma::BaseOrigin* origin, ma::usize size)
        : ma::HashMap<ma::u32, State*>(origin, size)
        , m_active {0}
    { }

    template <class State>
    bool
    StateMachine<State>::insert(ma::u32 index, State* state)
    {
        auto& super = (ma::HashMap<ma::u32, State*>&) *this;

        if ( index != 0 && state != 0 ) {
            state->set_code(index);

            return super
                .insert(index, state);
        }

        return false;
    }

    template <class State>
    bool
    StateMachine<State>::launch(ma::u32 index)
    {
        auto& super = (ma::HashMap<ma::u32, State*>&) *this;

        if ( this->m_active != 0 )
            this->m_active->leave();

        if ( super.contains(index) == true ) {
            this->m_active = super[index];
            this->m_active->enter();
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
