#include <faze/Screen.hpp>
#include <smal/Struct/import.hpp>

namespace fz
{
    Screen::Screen()
        : m_code {(ma::u32) -1}
        , m_next {(ma::u32) -1}
    { }

    ma::u32
    Screen::code() const
    {
        return this->m_code;
    }

    ma::u32
    Screen::next() const
    {
        return this->m_next;
    }

    void
    Screen::set_code(ma::u32 code)
    {
        this->m_code = code;
    }

    void
    Screen::set_next(ma::u32 next)
    {
        this->m_next = next;
    }
} // namespace fz
