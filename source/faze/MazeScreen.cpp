#include <faze/MazeScreen.hpp>

namespace fz
{
    // clang-format off
    static u32 g_room_0[16] = {
        0, 0, 0, 0,
        0, 1, 1, 0,
        0, 1, 1, 0,
        0, 0, 0, 0,
    };

    static u32 g_room_1[16] = {
        0, 1, 1, 0,
        0, 1, 1, 0,
        0, 1, 1, 0,
        0, 0, 0, 0,
    };

    static u32 g_room_2[16] = {
        0, 0, 0, 0,
        0, 1, 1, 1,
        0, 1, 1, 1,
        0, 0, 0, 0,
    };

    static u32 g_room_3[16] = {
        0, 1, 1, 0,
        0, 1, 1, 1,
        0, 1, 1, 1,
        0, 0, 0, 0,
    };

    static u32 g_room_4[16] = {
        0, 0, 0, 0,
        0, 1, 1, 0,
        0, 1, 1, 0,
        0, 1, 1, 0,
    };

    static u32 g_room_5[16] = {
        0, 1, 1, 0,
        0, 1, 1, 0,
        0, 1, 1, 0,
        0, 1, 1, 0,
    };

    static u32 g_room_6[16] = {
        0, 0, 0, 0,
        0, 1, 1, 1,
        0, 1, 1, 1,
        0, 1, 1, 0,
    };

    static u32 g_room_7[16] = {
        0, 1, 1, 0,
        0, 1, 1, 1,
        0, 1, 1, 1,
        0, 1, 1, 0,
    };

    static u32 g_room_8[16] = {
        0, 0, 0, 0,
        1, 1, 1, 0,
        1, 1, 1, 0,
        0, 0, 0, 0,
    };

    static u32 g_room_9[16] = {
        0, 1, 1, 0,
        1, 1, 1, 0,
        1, 1, 1, 0,
        0, 0, 0, 0,
    };

    static u32 g_room_a[16] = {
        0, 0, 0, 0,
        1, 1, 1, 1,
        1, 1, 1, 1,
        0, 0, 0, 0,
    };

    static u32 g_room_b[16] = {
        0, 1, 1, 0,
        1, 1, 1, 1,
        1, 1, 1, 1,
        0, 0, 0, 0,
    };

    static u32 g_room_c[16] = {
        0, 0, 0, 0,
        1, 1, 1, 0,
        1, 1, 1, 0,
        0, 1, 1, 0,
    };

    static u32 g_room_d[16] = {
        0, 1, 1, 0,
        1, 1, 1, 0,
        1, 1, 1, 0,
        0, 1, 1, 0,
    };

    static u32 g_room_e[16] = {
        0, 0, 0, 0,
        1, 1, 1, 1,
        1, 1, 1, 1,
        0, 1, 1, 0,
    };

    static u32 g_room_f[16] = {
        0, 1, 1, 0,
        1, 1, 1, 1,
        1, 1, 1, 1,
        0, 1, 1, 0,
    };
    // clang-format on

    static u32* g_room[16] = {
        (u32*) g_room_0,
        (u32*) g_room_1,
        (u32*) g_room_2,
        (u32*) g_room_3,
        (u32*) g_room_4,
        (u32*) g_room_5,
        (u32*) g_room_6,
        (u32*) g_room_7,
        (u32*) g_room_8,
        (u32*) g_room_9,
        (u32*) g_room_a,
        (u32*) g_room_b,
        (u32*) g_room_c,
        (u32*) g_room_d,
        (u32*) g_room_e,
        (u32*) g_room_f,
    };

    MazeScreen::MazeScreen()
        : Screen()
        , m_maze {g_view_x / 4u, g_view_y / 4u}
        , m_create {true}
        , m_tiletx {}
        , m_tilesp {}
        , m_player {}
    {
        m_tilesp.setTexture(m_tiletx);
        m_tilesp.setScale({g_scale_x, g_scale_y});
    }

    bool
    MazeScreen::attach()
    {
        srand(time(0));

        if ( m_tiletx.loadFromFile("../assets/walls.png") )
            return m_maze.prepare();

        return false;
    }

    bool
    MazeScreen::handle(const sf::Event& event)
    {
        if ( event.type == sf::Event::Closed )
            return false;

        if ( event.type == sf::Event::KeyReleased ) {
            if ( event.key.code == sf::Keyboard::Escape )
                return false;
        }

        if ( event.type == sf::Event::KeyPressed ) {
            m_target.x = (event.key.code == sf::Keyboard::D) - (event.key.code == sf::Keyboard::A);
            m_target.y = (event.key.code == sf::Keyboard::S) - (event.key.code == sf::Keyboard::W);
        }

        return true;
    }

    void
    MazeScreen::update(f32 delta)
    {
        u32*  room = 0;
        Vec2u next;

        if ( m_create ) {
            m_create = (generate(rand() % 16 + 48) == false);
            m_player = {
                m_maze.start().x * 4 + 4 / 2,
                m_maze.start().y * 4 + 4 / 2,
            };
        }

        if ( m_target.x * m_target.y == 0 ) {
            next = m_player + m_target;
            room = g_room[m_maze.find(next / 4).type];

            if ( room[((next.y) % 4) * 4 + ((next.x) % 4)] != 0 )
                m_player = next;
        }

        if ( m_player / 4 == m_maze.exit() )
            m_create = true;

        m_target = {0};
    }

    void
    MazeScreen::render(sf::RenderTarget& target)
    {
        u32*  room = 0;
        Vec2u txtr;

        for ( u32 i = 0; i < m_maze.height(); i++ ) {
            for ( u32 j = 0; j < m_maze.width(); j++ ) {
                room = g_room[m_maze.find(j, i).type];

                if ( m_maze.find(j, i).type == 0 )
                    continue;

                for ( u32 k = 0; k < 4; k++ ) {
                    for ( u32 l = 0; l < 4; l++ ) {
                        txtr = {0, room[k * 4 + l] * 16};

                        m_tilesp.setPosition({
                            (l + (j * 4)) * g_tile_x * g_scale_x,
                            (k + (i * 4)) * g_tile_y * g_scale_y,
                        });

                        m_tilesp.setTextureRect({
                            (i32) (txtr.x * g_tile_x),
                            (i32) (txtr.y * g_tile_y),
                            (i32) (g_tile_x),
                            (i32) (g_tile_y),
                        });

                        target.draw(m_tilesp);
                    }
                }
            }
        }

        m_tilesp.setPosition({
            m_player.x * g_tile_x * g_scale_x,
            m_player.y * g_tile_y * g_scale_y,
        });

        m_tilesp.setTextureRect({
            (i32) (0 * g_tile_x),
            (i32) (17 * g_tile_y),
            (i32) (g_tile_x),
            (i32) (g_tile_y),
        });

        target.draw(m_tilesp);
    }

    bool
    MazeScreen::generate(u32 steps)
    {
        static const char* s_colors[] = {
            "\x1b[30;40m", // none
            "\x1b[34:44m", // room
            "\x1b[31;41m", // start
            "\x1b[32;42m", // exit
        };

        if ( m_maze.prepare() == false )
            return false;

        m_maze.generate(steps);

        system("clear");

        for ( u32 i = 0; i < m_maze.height(); i++ ) {
            for ( u32 j = 0; j < m_maze.width(); j++ ) {
                if ( m_maze.start() == Vec2u {j, i} )
                    printf("%s", s_colors[2]);
                else if ( m_maze.exit() == Vec2u {j, i} )
                    printf("%s", s_colors[3]);
                else
                    printf("%s", s_colors[m_maze.find(j, i).type != 0]);

                printf("%x\x1b[0m ", m_maze.find(j, i).type);
            }

            printf("\n");
        }

        return true;
    }
} // namespace fz
