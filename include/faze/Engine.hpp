#ifndef FAZE_ENGINE_HPP
#define FAZE_ENGINE_HPP

#include <faze/StateMachine.hpp>
#include <faze/Screen.hpp>

namespace fz
{
    // Move after resource management
    static const ma::f32 g_aspect_width  = 16;
    static const ma::f32 g_aspect_height = 9;

    static const ma::u32 g_window_width  = 720;
    static const ma::u32 g_window_height = g_window_width *
                                           (g_aspect_height /
                                               g_aspect_width);

    static const ma::u32 g_window_cx = g_window_width / 2;
    static const ma::u32 g_window_cy = g_window_height / 2;

    static const ma::f32 g_tile_width  = 16;
    static const ma::f32 g_tile_height = 16;

    static const ma::u32 g_matrix_width  = 16;
    static const ma::u32 g_matrix_height = 9;

    static const ma::f32 g_factor_width = g_window_width /
                                          (g_matrix_width *
                                              g_tile_width);
    static const ma::f32 g_factor_height = g_window_height /
                                           (g_matrix_height *
                                               g_tile_height);

    class Engine
    {
    public:
        Engine(ma::BaseOrigin* origin, ma::usize size);

        bool
        is_active() const;

        void
        loop(ma::usize screen, ma::usize frames = 60);

        StateMachine<Screen>&
        states();

        const StateMachine<Screen>&
        states() const;

    private:
        void
        handle(const sf::Event& event);

        void
        update(float delta);

        void
        render(sf::RenderWindow& window);

    public:
        // Move after resource management
        sf::VideoMode win_vmode = {g_window_width, g_window_height};
        const char*   win_title = "Faze";
        ma::usize     win_style = sf::Style::Default;

    private:
        sf::RenderWindow m_window;
        sf::Clock        m_clock;
        bool             m_active;

        StateMachine<Screen> m_states;
    };
} // namespace fz

#endif // FAZE_ENGINE_HPP
