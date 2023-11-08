#include <faze/import.hpp>

enum Screens
{
    A = 1,
    B,
    C,

    SIZE,
};

class AScreen
    : public fz::Screen
{
public:
    AScreen()
        : Screen()
    {
        this->set_next(Screens::B);
    }

    void
    on_enter()
    {
        printf("AScreen starting...\n");
    }

    void
    on_leave()
    {
        printf("AScreen stopping...\n");
    }

    bool
    on_handle(const sf::Event& event)
    {
        if ( event.type == sf::Event::Closed ) {
            this->set_next(Screens::C);

            return false;
        }

        if ( event.type == sf::Event::KeyReleased ) {
            if ( event.key.code == sf::Keyboard::Escape )
                return false;
        }

        return true;
    }

    void
    on_update(float delta)
    { }

    void
    on_render(sf::RenderTarget& target)
    {
        sf::RectangleShape rect;

        ma::f32 half  = 75;
        ma::f32 width = half * 2;

        rect.setPosition({fz::g_window_cx - half, fz::g_window_cy - half});
        rect.setSize({width, width});
        rect.setFillColor(sf::Color {0, 0, 192});

        target.draw(rect);
    }
};

class BScreen
    : public fz::Screen
{
public:
    BScreen()
        : Screen()
    {
        this->set_next(Screens::C);
    }

    void
    on_enter()
    {
        printf("BScreen starting...\n");
    }

    void
    on_leave()
    {
        printf("BScreen stopping...\n");
    }

    bool
    on_handle(const sf::Event& event)
    {
        if ( event.type == sf::Event::Closed )
            return false;

        if ( event.type == sf::Event::KeyReleased ) {
            if ( event.key.code == sf::Keyboard::Escape )
                return false;
        }

        return true;
    }

    void
    on_update(float delta)
    { }

    void
    on_render(sf::RenderTarget& target)
    {
        sf::CircleShape circ;

        ma::f32 radius = 75;

        circ.setPosition({fz::g_window_cx - radius, fz::g_window_cy - radius});
        circ.setRadius(radius);
        circ.setFillColor(sf::Color {0, 192, 0});

        target.draw(circ);
    }
};

class CScreen
    : public fz::Screen
{
public:
    CScreen()
        : Screen()
    { }

    void
    on_enter()
    {
        printf("CScreen starting...\n");
    }

    void
    on_leave()
    {
        printf("CScreen stopping...\n");
    }

    bool
    on_handle(const sf::Event& event)
    {
        if ( event.type == sf::Event::Closed )
            return false;

        if ( event.type == sf::Event::KeyReleased ) {
            if ( event.key.code == sf::Keyboard::Escape )
                return false;
        }

        return true;
    }

    void
    on_update(float delta)
    { }

    void
    on_render(sf::RenderTarget& target)
    {
        sf::RectangleShape rect;

        ma::f32 half  = 150;
        ma::f32 width = half * 2;

        rect.setPosition({fz::g_window_cx - half, fz::g_window_cy - half});
        rect.setSize({width, width});
        rect.setFillColor(sf::Color {192, 0, 0});

        target.draw(rect);
    }
};

int
main(int argc, const char* argv[])
{
    char* memory = (char*) calloc(1, 65536);

    {
        auto pool = ma::PoolOrigin {memory, 65536, 8192};
        auto game = fz::Engine {&pool, 16};

        AScreen a;
        BScreen b;
        CScreen c;

        game.states().insert(Screens::A, &a);
        game.states().insert(Screens::B, &b);
        game.states().insert(Screens::C, &c);

        if ( game.is_active() )
            game.loop(Screens::A);
    }

    free(memory);

    return 0;
}
