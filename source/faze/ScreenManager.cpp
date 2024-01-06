#include <faze/ScreenManager.hpp>

namespace fz
{
    ScreenManager::ScreenManager(u32 size)
        : m_table {g_origin, size}
        , m_stack {g_origin, size}
    { }

    bool
    ScreenManager::insert(String name, Screen& screen)
    {
        bool flag = false;

        if ( name == 0 ) return false;

        if ( m_table.insert(name, &screen) ) {
            if ( screen.attach() == false )
                m_table.remove(name);
            else
                flag = true;
        }

        return flag;
    }

    bool
    ScreenManager::remove(String name)
    {
        Screen* screen = 0;

        if ( m_table.contains(name) ) {
            screen = m_table[name];

            if ( screen->detach() == true )
                return m_table.remove(name);
        }

        return false;
    }

    bool
    ScreenManager::launch(String name)
    {
        Screen* screen = active();
        bool    flag   = false;

        if ( screen != 0 ) screen->leave();

        if ( m_table.contains(name) ) {
            screen = m_table[name];

            if ( screen != 0 )
                flag = m_stack.insert(screen);
        } else {
            m_stack.remove();
            screen = active();

            if ( screen != 0 )
                flag = true;
        }

        if ( flag ) screen->enter();

        return flag;
    }

    Screen*
    ScreenManager::active()
    {
        Screen* screen = 0;

        if ( m_stack.isEmpty() == false )
            screen = m_stack[m_stack.count() - 1];

        return screen;
    }

    Screen*
    ScreenManager::active() const
    {
        Screen* screen = 0;

        if ( m_stack.isEmpty() == false )
            screen = m_stack[m_stack.count() - 1];

        return screen;
    }
} // namespace fz
