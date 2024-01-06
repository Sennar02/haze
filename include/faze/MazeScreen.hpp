#ifndef FAZE_MAZE_SCREEN_HPP
#define FAZE_MAZE_SCREEN_HPP

#include <faze/Screen.hpp>
#include <faze/Maze.hpp>

namespace fz
{
    class MazeScreen
        : public Screen
    {
    public:
        /**
         *
         */
        MazeScreen();

        /**
         *
         */
        bool
        attach();

        /**
         *
         */
        bool
        handle(const sf::Event& event);

        /**
         *
         */
        void
        update(f32 delta);

        /**
         *
         */
        void
        render(sf::RenderTarget& target);

    private:
        /**
         *
         */
        bool
        generate(u32 steps);

    private:
        /**
         *
         */
        Maze m_maze;

        /**
         *
         */
        bool m_create;

        /**
         *
         */
        sf::Texture m_tiletx;

        /**
         *
         */
        sf::Sprite m_tilesp;

        /**
         *
         */
        Vec2u m_player;

        /**
         *
         */
        Vec2i m_target;
    };
} // namespace fz

#endif // FAZE_MAZE_SCREEN_HPP
