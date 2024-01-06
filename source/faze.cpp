#include <faze/import.hpp>

int
main(int argc, const char* argv[])
{
    auto game = fz::Engine {16};
    auto maze = fz::MazeScreen {};

    game.insert("Gioco", maze);

    if ( game.isActive() )
        return game.loop("Gioco", 120) == false;

    return 0;
}
