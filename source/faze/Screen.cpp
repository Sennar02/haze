#include <faze/Screen.hpp>
#include <smal/Struct/import.hpp>

namespace fz
{
    Screen::Screen()
        : m_index {0}
        , m_event {0}
    { }

    ma::u16
    Screen::index() const
    {
        return this->m_index;
    }

    ma::u16
    Screen::event() const
    {
        return this->m_event;
    }

    void
    Screen::set_index(ma::u16 index)
    {
        this->m_index = index;
    }

    void
    Screen::set_event(ma::u16 event)
    {
        this->m_event = event;
    }
} // namespace fz
