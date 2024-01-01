#ifndef FAZE_TITLE_SCREEN_HPP
#define FAZE_TITLE_SCREEN_HPP

#include <faze/State.hpp>

namespace fz
{
    class TitleState
        : public State
    {
    public:
        TitleState();

        void
        enter();

        void
        leave();

        bool
        attach();

        void
        detach();

        ma::u16
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
