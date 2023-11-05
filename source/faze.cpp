#include <faze/import.hpp>

class SplashScreen
    : public fz::Screen
{
public:
    SplashScreen()
        : Screen(1)
    {
        this->set_next(2);
    }

    void
    startup()
    {
        printf("SplashScreen starting...\n");
    }

    void
    cleanup()
    {
        printf("SplashScreen stopping...\n");
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

class ConfigScreen
    : public fz::Screen
{
public:
    ConfigScreen()
        : Screen(2)
    {
        this->set_next(3);
    }

    void
    startup()
    {
        printf("ConfigScreen starting...\n");
    }

    void
    cleanup()
    {
        printf("ConfigScreen stopping...\n");
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

class EndingScreen
    : public fz::Screen
{
public:
    EndingScreen()
        : Screen(3)
    { }

    void
    startup()
    {
        printf("EndingScreen starting...\n");
    }

    void
    cleanup()
    {
        printf("EndingScreen stopping...\n");
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

        auto splash = SplashScreen {};
        auto config = ConfigScreen {};
        auto ending = EndingScreen {};

        game.states().insert(&splash);
        game.states().insert(&config);
        game.states().insert(&ending);

        if ( game.is_active() )
            game.loop(splash.self());
    }

    free(memory);

    return 0;
}
