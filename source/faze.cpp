#include <faze/import.hpp>

int
main(int argc, const char* argv[])
{
    char* memory = (char*) calloc(1, 65536);

    {
        auto pool = ma::PoolOrigin {memory, 65536, 8192};
        auto game = fz::Engine {&pool, 16};

        fz::TitleScreen  title;
        fz::ConfigScreen config;

        game.states().insert({fz::Screens::Start, 0, fz::Screens::Title}, &title);
        game.states().insert({fz::Screens::Title, 0, fz::Screens::Config}, &config);

        if ( game.is_active() )
            game.loop(fz::Screens::Start);
    }

    free(memory);

    return 0;
}
