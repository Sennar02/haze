#ifndef FAZE_STATE_TRANSIT_HPP
#define FAZE_STATE_TRANSIT_HPP

#include <faze/define.hpp>

namespace fz
{
    struct StateTransit
    {
        ma::u16 state;
        ma::u16 event;

        ma::u16 next;
    };
} // namespace fz

#endif // FAZE_STATE_TRANSIT_HPP
