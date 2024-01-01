#include <faze/import.hpp>

int
main(int argc, const char* argv[])
{
    char* memory = (char*) calloc(1, 65536);

    {
        auto pool = ma::PoolOrigin {memory, 65536, 8192};
        auto game = fz::Engine {&pool, 16};

        fz::TitleState  title;
        fz::ConfigState config;

        game.states().insert({fz::States::Start, 0, fz::States::Title}, &title);
        game.states().insert({fz::States::Title, 1, fz::States::Config}, &config);

        if ( game.is_active() )
            game.loop(fz::States::Start);
    }

    free(memory);

    return 0;
}
