#ifndef DEMO_DUNGEON_HPP
#define DEMO_DUNGEON_HPP

#include <faze/Buffer2D.hpp>
#include <faze/util.hpp>

namespace fz
{
    enum class Direction
    {
        None,
        North = 1u,
        East  = 2u,
        South = 4u,
        West  = 8u,
    };

    struct Room
    {
        u8  type;
        u32 dist;
    };

    class Maze
        : public Buffer2D<Room>
    {
    public:
        /**
         *
         */
        Maze(u32 width, u32 height);

        /**
         *
         */
        bool
        prepare();

        /**
         *
         */
        Vec2u
        generate(u32 steps, const Vec2u& start);

        /**
         *
         */
        Vec2u
        generate(u32 steps);

        /**
         *
         */
        Vec2u
        exit() const;

        /**
         *
         */
        Vec2u
        start() const;

        /**
         *
         */
        bool
        contains(const Vec2u& pos) const;

    private:
        /**
         *
         */
        bool
        step(const Vec2u& pos, u32 dir);

    private:
        /**
         *
         */
        ArrayList<Vec2u> m_coords;

        /**
         *
         */
        Vec2u m_center;

        /**
         *
         */
        Vec2u m_exit;

        /**
         *
         */
        Vec2u m_start;
    };
} // namespace fz

#endif // DEMO_DUNGEON_HPP
