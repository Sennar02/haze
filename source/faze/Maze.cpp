#include <faze/Maze.hpp>
#include <unistd.h>

namespace fz
{
    static const u32 g_dir_count = 4u;
    static const u32 g_end_count = 16u;

    static const u8 g_dir[g_dir_count] = {
        (u8) Direction::North,
        (u8) Direction::East,
        (u8) Direction::South,
        (u8) Direction::West,
    };

    static const bool g_end[g_end_count] = {
        true,
        true,
        true,
        false,
        true,
        false,
        false,
        false,
        true,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
    };

    static const Vec2i g_vec[g_dir_count] = {
        { 0, -1}, // north
        { 1,  0}, // east
        { 0,  1}, // south
        {-1,  0}, // west
    };

    static u32 g_idx[g_dir_count] =
        {0, 1u, 2u, 3u};

    Maze::Maze(u32 width, u32 height)
        : Buffer2D<Room>(g_origin, width * height, width)
        , m_coords {width * height}
        , m_center {width / 2, height / 2}
        , m_exit {}
        , m_start {}
    { }

    bool
    Maze::prepare()
    {
        auto& self = (Buffer2D<Room>::Parent&) *this;
        u32   size = self.size();

        for ( u32 i = 0; i < size; i++ )
            self.find(i) = {0, 0};

        return true;
    }

    Vec2u
    Maze::generate(u32 steps, const Vec2u& start)
    {
        u32   index = 0;
        Vec2u posit;
        Vec2u point;

        if ( contains(start) == false ) return {};

        m_coords.insert(start);
        m_exit = m_start = start;

        find(m_start).dist = 1;

        for ( u32 s = 0; s < steps; s++ ) {
            if ( m_coords.isEmpty() ) break;

            index = rand() % m_coords.count();
            posit = m_coords.find(index);

            shuffle(g_idx, g_dir_count);

            for ( u32 i = 0; i < g_dir_count; i++ ) {
                if ( step(posit, g_idx[i]) == false )
                    index = g_max_u32, i = g_dir_count;
            }

            if ( index != g_max_u32 )
                m_coords.remove(index);
        }

        m_coords.clear();

        for ( u32 i = 0; i < height(); i++ ) {
            for ( u32 j = 0; j < width(); j++ )
                find(j, i).dist = steps;
        }

        m_coords.insert(m_start);
        find(m_start).dist = 1;

        while ( m_coords.isEmpty() == false ) {
            index = 0;
            posit = m_coords.find(index);

            for ( u32 i = 0; i < g_dir_count; i++ ) {
                point = posit + g_vec[i];

                if ( (find(posit).type & g_dir[i]) != 0 ) {
                    if ( find(point).dist == steps )
                        m_coords.insert(point);

                    if ( find(point).dist > find(posit).dist + 1 )
                        find(point).dist = find(posit).dist + 1;

                    if ( find(point).dist > find(m_exit).dist && g_end[find(point).type] == true )
                        m_exit = point;
                }
            }

            m_coords.remove(index);
        }

        return start;
    }

    Vec2u
    Maze::generate(u32 steps)
    {
        return generate(steps, m_center);
    }

    Vec2u
    Maze::exit() const
    {
        return m_exit;
    }

    Vec2u
    Maze::start() const
    {
        return m_start;
    }

    bool
    Maze::contains(const Vec2u& pos) const
    {
        return pos.x < width() &&
               pos.y < height();
    }

    bool
    Maze::step(const Vec2u& pos, u32 dir)
    {
        Vec2u vec  = pos + g_vec[dir];
        u32   dist = 0;

        if ( contains(vec) && find(vec).type == 0 ) {
            find(pos).type |= g_dir[dir];
            find(vec).type |= g_dir[(dir + 2) % g_dir_count];

            dist           = find(pos).dist + 1;
            find(vec).dist = dist;

            if ( dist > find(m_start).dist && g_end[find(vec).type] == true )
                m_start = vec;

            return m_coords.insert(vec) == false;
        }

        if ( contains(vec) && g_end[find(vec).type] == true ) {
            if ( rand() % 3 == 0 )
                return true;

            find(pos).type |= g_dir[dir];
            find(vec).type |= g_dir[(dir + 2) % g_dir_count];
        }

        return true;
    }
} // namespace fz
