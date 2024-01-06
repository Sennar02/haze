#ifndef FAZE_DEFINE_HPP
#define FAZE_DEFINE_HPP

#include <faze/depend.hpp>

namespace fz
{
    using namespace ma;

    // Move after resource management
    static const ma::f32 g_aspect_width  = 16;
    static const ma::f32 g_aspect_height = 9;

    static const ma::u32 g_window_width  = 1280;
    static const ma::u32 g_window_height = g_window_width *
                                           (g_aspect_height /
                                               g_aspect_width);

    static const ma::u32 g_window_cx = g_window_width / 2;
    static const ma::u32 g_window_cy = g_window_height / 2;

    static const u32 g_tile_x = 32u;
    static const u32 g_tile_y = 32u;

    static const f32 g_scale_x = 0.5f;
    static const f32 g_scale_y = 0.5f;

    static const u32 g_view_x = g_window_width / (g_tile_x * g_scale_x);
    static const u32 g_view_y = g_window_height / (g_tile_y * g_scale_y);

    class Screen;
    class ScreenManager;

    class Engine;
    class Dungeon;

    template <class Item>
    class Vec2;

    template <class Item, template <class> class Parent>
    class Buffer2D;
} // namespace fz

#endif // FAZE_DEFINE_HPP
