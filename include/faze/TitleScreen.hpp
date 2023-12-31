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
        enter();

        void
        leave();

        ma::u32
        handle(const sf::Event& event);

        void
        update(float delta);

        void
        render(sf::RenderTarget& target);

    private:
        sf::Font m_font;
        sf::Text m_text;
    };
} // namespace fz

#endif // FAZE_TITLE_SCREEN_HPP
