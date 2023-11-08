#include <faze/Screen.hpp>
#include <smal/Struct/import.hpp>

namespace fz
{
    Screen::Screen()
        : m_code {0}
        , m_next {0}
    { }

    ma::usize
    Screen::code() const
    {
        return this->m_code;
    }

    ma::usize
    Screen::next() const
    {
        return this->m_next;
    }

    void
    Screen::set_code(ma::usize code)
    {
        this->m_code = code;
    }

    void
    Screen::set_next(ma::usize next)
    {
        this->m_next = next;
    }
} // namespace fz
