#ifndef FAZE_ENGINE_HPP
#define FAZE_ENGINE_HPP

#include <faze/ScreenManager.hpp>

namespace fz
{
    class Engine
        : public ScreenManager
    {
    public:
        /**
         *
         */
        Engine(u32 size);

        /**
         *
         */
        bool
        isActive() const;

        /**
         *
         */
        bool
        loop(String name, u32 frames = 60);

    private:
        /**
         *
         */
        void
        handle(const sf::Event& event);

        /**
         *
         */
        void
        update(const sf::Time& delta);

        /**
         *
         */
        void
        render();

    public:
        // Move after resource management
        sf::VideoMode win_vmode = {g_window_width, g_window_height};
        const char*   win_title = "Faze";
        u32           win_style = sf::Style::Default;

    private:
        /**
         *
         */
        bool m_active;

        /**
         *
         */
        sf::RenderWindow m_window;

        /**
         *
         */
        sf::Clock m_clock;
    };
} // namespace fz

#endif // FAZE_ENGINE_HPP
