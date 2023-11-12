#include <faze/LevelScreen.hpp>
#include <faze/Engine.hpp>

namespace fz
{
    LevelScreen::LevelScreen()
        : Screen()
        , m_font {}
        , m_text {}
    {
        if ( this->m_font.loadFromFile("../assets/jetbrains-mono-regular.ttf") == false )
            return;

        this->set_next(Screens::Exit);

        this->m_text.setFont(this->m_font);
        this->m_text.setCharacterSize(20);
        this->m_text.setFillColor(sf::Color::Red);
        this->m_text.setString("LEVEL");

        auto size = this->m_text.getGlobalBounds();

        this->m_text.setPosition(
            g_window_cx - size.width / 2,
            g_window_cy - size.height / 2);
    }

    void
    LevelScreen::enter()
    { }

    void
    LevelScreen::leave()
    { }

    ma::u32
    LevelScreen::handle(const sf::Event& event)
    {
        if ( event.type == sf::Event::Closed )
            return this->next();

        if ( event.type == sf::Event::KeyReleased ) {
            if ( event.key.code == sf::Keyboard::Escape )
                return this->next();
        }

        return 0;
    }

    void
    LevelScreen::update(float delta)
    { }

    void
    LevelScreen::render(sf::RenderTarget& target)
    {
        target.draw(this->m_text);
    }
} // namespace fz
