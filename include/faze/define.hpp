#ifndef FAZE_DEFINE_HPP
#define FAZE_DEFINE_HPP

#include <faze/depend.hpp>

namespace fz
{
    class Engine;
    class Screen;

    struct StateTransit;

    template <class State>
    class StateMachine;

    enum Screens
    {
        Start = 1,
        Title,
        Config,
        Exit,

        SIZE,
    };
} // namespace fz

#endif // FAZE_DEFINE_HPP
