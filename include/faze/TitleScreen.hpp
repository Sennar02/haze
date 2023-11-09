#ifndef FAZE_TITLE_SCREEN_HPP
#define FAZE_TITLE_SCREEN_HPP

#include <faze/Screen.hpp>

namespace fz
{
    class TitleScreen
        : public Screen
    {
    public:
        TitleScreen();

        void
        on_enter();

        void
        on_leave();

        bool
        on_handle(const sf::Event& event);

        void
        on_update(float delta);

        void
        on_render(sf::RenderTarget& target);

    private:
        sf::Font m_font;
        sf::Text m_text;
    };
} // namespace fz

#endif // FAZE_TITLE_SCREEN_HPP
