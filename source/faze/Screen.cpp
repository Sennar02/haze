#include <faze/Screen.hpp>
#include <smal/Struct/import.hpp>

namespace fz
{
    Screen::Screen(ma::usize self)
        : m_self {self}
        , m_next {0}
    { }

    ma::usize
    Screen::self() const
    {
        return this->m_self;
    }

    ma::usize
    Screen::next() const
    {
        return this->m_next;
    }

    void
    Screen::set_next(ma::usize next)
    {
        this->m_next = next;
    }
} // namespace fz
