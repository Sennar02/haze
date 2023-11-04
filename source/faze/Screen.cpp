#include <faze/Screen.hpp>
#include <smal/Struct/import.hpp>

namespace fz
{
    Screen::Screen(ma::u16 code)
        : m_code {code}
        , m_next {0}
    { }

    ma::u16
    Screen::code() const
    {
        return this->m_code;
    }

    ma::u16
    Screen::next() const
    {
        return this->m_next;
    }

    void
    Screen::set_next(ma::u16 next)
    {
        this->m_next = next;
    }

    ScreenChange::ScreenChange()
        : m_curr {0}
        , m_next {0}
    { }

    ScreenChange::ScreenChange(Screen& curr, Screen& next)
        : m_curr {curr.code()}
        , m_next {next.code()}
    { }

    ScreenChange::ScreenChange(ma::u16 curr, ma::u16 next)
        : m_curr {curr}
        , m_next {next}
    { }

    ma::u32
    ScreenChange::index() const
    {
        return this->m_index;
    }
} // namespace fz
