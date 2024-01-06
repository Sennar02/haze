#include <faze/util.hpp>

namespace fz
{
    template <class Type>
    void
    shuffle(Type* memory, u32 size)
    {
        for ( u32 i = 0; i < size / 2; i++ ) {
            u32 j = rand() % size;
            u32 k = rand() % size;

            swap(memory[j], memory[k]);
        }
    }
} // namespace fz
