#ifndef FAZE_LEVEL_SCREEN_HPP
#define FAZE_LEVEL_SCREEN_HPP

#include <faze/Screen.hpp>

namespace fz
{
    class LevelScreen
        : public Screen
    {
    public:
        LevelScreen();

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

#endif // FAZE_LEVEL_SCREEN_HPP
