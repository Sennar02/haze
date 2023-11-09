#ifndef FAZE_DEFINE_HPP
#define FAZE_DEFINE_HPP

#include <faze/depend.hpp>

namespace fz
{
    class Engine;
    class Screen;

    template <class State>
    class StateMachine;

    enum Screens
    {
        Title = 1,
        Game,
        Exit,

        SIZE,
    };
} // namespace fz

#endif // FAZE_DEFINE_HPP
