#include <faze/import.hpp>

class TitleScreen
    : public fz::Screen
{
public:
    TitleScreen()
        : Screen(1)
    {
        this->set_next(2);
    }

    void
    startup()
    {
        printf("TitleScreen starting...\n");
    }

    void
    cleanup()
    {
        printf("TitleScreen stopping...\n");
    }

    bool
    handle(const sf::Event& event)
    {
        if ( event.type == sf::Event::Closed ) {
            this->set_next(3);

            return false;
        }

        if ( event.type == sf::Event::KeyReleased ) {
            if ( event.key.code == sf::Keyboard::Escape )
                return false;
        }

        return true;
    }

    void
    update(float delta)
    { }

    void
    render(sf::RenderTarget& target)
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

class ConfgScreen
    : public fz::Screen
{
public:
    ConfgScreen()
        : Screen(2)
    {
        this->set_next(3);
    }

    void
    startup()
    {
        printf("ConfgScreen starting...\n");
    }

    void
    cleanup()
    {
        printf("ConfgScreen stopping...\n");
    }

    bool
    handle(const sf::Event& event)
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
    update(float delta)
    { }

    void
    render(sf::RenderTarget& target)
    {
        sf::CircleShape circ;

        ma::f32 radius = 75;

        circ.setPosition({fz::g_window_cx - radius, fz::g_window_cy - radius});
        circ.setRadius(radius);
        circ.setFillColor(sf::Color {0, 192, 0});

        target.draw(circ);
    }
};

class EndngScreen
    : public fz::Screen
{
public:
    EndngScreen()
        : Screen(3)
    { }

    void
    startup()
    {
        printf("EndngScreen starting...\n");
    }

    void
    cleanup()
    {
        printf("EndngScreen stopping...\n");
    }

    bool
    handle(const sf::Event& event)
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
    update(float delta)
    { }

    void
    render(sf::RenderTarget& target)
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

        auto title = TitleScreen {};
        auto confg = ConfgScreen {};
        auto endng = EndngScreen {};

        auto t_to_c = fz::ScreenChange {title, confg};
        auto c_to_e = fz::ScreenChange {confg, endng};
        auto t_to_e = fz::ScreenChange {title, endng};

        game.states().insert(t_to_c, &confg);
        game.states().insert(c_to_e, &endng);
        game.states().insert(t_to_e, &endng);

        if ( game.is_active() )
            game.loop(&title);
    }

    free(memory);

    return 0;
}
