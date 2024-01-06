#ifndef FAZE_SCREEN_MANAGER_HPP
#define FAZE_SCREEN_MANAGER_HPP

#include <faze/Screen.hpp>

namespace fz
{
    class ScreenManager
    {
    public:
        /**
         *
         */
        ScreenManager(u32 size);

        /**
         *
         */
        bool
        insert(String name, Screen& screen);

        /**
         *
         */
        bool
        remove(String name);

        /**
         *
         */
        bool
        launch(String name);

        /**
         *
         */
        Screen*
        active();

        /**
         *
         */
        Screen*
        active() const;

    protected:
        /**
         *
         */
        HashTable<String, Screen*> m_table;

        /**
         *
         */
        ArrayStack<Screen*> m_stack;
    };
} // namespace fz

#endif // FAZE_SCREEN_MANAGER_HPP
