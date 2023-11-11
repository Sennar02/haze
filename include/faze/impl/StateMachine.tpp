#include <faze/StateMachine.hpp>

namespace fz
{
    namespace impl
    {
        union StateTransit
        {
        public:
            StateTransit(ma::u16 index, ma::u16 event)
                : m_index {index}
                , m_event {event}
            { }

            ma::u32
            total() const
            {
                return this->m_total;
            }

        private:
            struct
            {
                ma::u16 m_index;
                ma::u16 m_event;
            };

            ma::u32 m_total;
        };
    }; // namespace impl

    template <class State>
    StateMachine<State>::StateMachine(ma::BaseOrigin* origin, ma::usize size)
        : m_holder {origin, size}
        , m_active {0}
    { }

    template <class State>
    bool
    StateMachine<State>::contains(ma::u16 index, ma::u16 event) const
    {
        auto transit =
            impl::StateTransit {index, event};

        return this->m_holder.contains(transit.total());
    }

    template <class State>
    bool
    StateMachine<State>::insert(const StateTransit& transit, State* state)
    {
        auto helper =
            impl::StateTransit {transit.state, transit.event};

        if ( state == 0 || helper.total() == 0 )
            return false;

        state->set_index(transit.next);

        return this->m_holder
            .insert(helper.total(), state);
    }

    template <class State>
    bool
    StateMachine<State>::remove(ma::u16 index, ma::u16 event)
    {
        auto transit =
            impl::StateTransit {index, event};

        return this->m_holder.remove(transit.total());
    }

    template <class State>
    bool
    StateMachine<State>::launch(ma::u16 index, ma::u16 event)
    {
        auto transit =
            impl::StateTransit {index, event};

        if ( this->m_active != 0 )
            this->m_active->on_leave();

        if ( this->m_holder.contains(transit.total()) == true ) {
            this->m_active = this->m_holder[transit.total()];
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
