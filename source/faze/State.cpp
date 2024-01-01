#include <faze/State.hpp>
#include <smal/Struct/import.hpp>

namespace fz
{
    State::State(ma::u16 family)
        : m_family {family}
        , m_status {(ma::u16) -1}
    { }

    ma::u16
    State::status() const
    {
        return this->m_status;
    }

    void
    State::set_status(ma::u16 status)
    {
        this->m_status = status;
    }

    ma::u16
    State::family() const
    {
        return this->m_family;
    }
} // namespace fz
