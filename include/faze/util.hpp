#ifndef FAZE_UTIL_HPP
#define FAZE_UTIL_HPP

#include <faze/define.hpp>

namespace fz
{
    template <class Type>
    void
    shuffle(Type* memory, u32 size);
} // namespace fz

#include <faze/inline/util.inl>

#endif // FAZE_UTIL_HPP
