#include <faze/TitleScreen.hpp>
#include <faze/Engine.hpp>

namespace fz
{
    TitleScreen::TitleScreen()
        : Screen()
        , m_font {}
        , m_text {}
    {
        auto pos = sf::Vector2f {10, 10};

        if ( this->m_font.loadFromFile("../assets/jetbrains-mono-regular.ttf") == false )
            return;

        this->m_text.setFont(this->m_font);
        this->m_text.setCharacterSize(20);
        this->m_text.setString("Ghesboro");

        auto siz = this->m_text.getGlobalBounds();

        this->m_text.setOrigin(
            (ma::u32) siz.left + siz.width / 2,
            (ma::u32) siz.top + siz.height / 2);

        this->m_text.setPosition(g_window_cx, g_window_cy);
        this->m_text.setColor(sf::Color::Black);
    }

    void
    TitleScreen::on_enter()
    { }

    void
    TitleScreen::on_leave()
    { }

    bool
    TitleScreen::on_handle(const sf::Event& event)
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
    TitleScreen::on_update(float delta)
    { }

    void
    TitleScreen::on_render(sf::RenderTarget& target)
    {
        target.draw(this->m_text);
    }
} // namespace fz
