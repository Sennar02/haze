#include <faze/Screen.hpp>

namespace fz
{
    Screen::Screen()
        : m_next {0}
    { }

    bool
    Screen::isActive() const
    {
        if ( m_next == "" )
            return false;

        return true;
    }

    bool
    Screen::setNext(String next)
    {
        m_next = next;

        if ( m_next == "" )
            return false;

        return true;
    }

    String
    Screen::next()
    {
        return exch(m_next, String {""});
    }

    void
    Screen::enter()
    { }

    void
    Screen::leave()
    { }

    bool
    Screen::attach()
    {
        return true;
    }

    bool
    Screen::detach()
    {
        return true;
    }
} // namespace fz
