#include <faze/import.hpp>

int
main(int argc, const char* argv[])
{
    char* memory = (char*) calloc(1, 65536);

    {
        auto pool = ma::PoolOrigin {memory, 65536, 8192};
        auto game = fz::Engine {&pool, 16};

        fz::TitleScreen title;

        game.states().insert(fz::Screens::Title, &title);

        if ( game.is_active() )
            game.loop(fz::Screens::Title);
    }

    free(memory);

    return 0;
}
