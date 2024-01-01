#include <faze/TitleState.hpp>
#include <faze/Engine.hpp>

namespace fz
{
    TitleState::TitleState()
        : State(States::Title)
        , m_font {}
        , m_text {}
    {
        if ( this->m_font.loadFromFile("../assets/jetbrains-mono-regular.ttf") == false )
            return;

        this->m_text.setFont(this->m_font);
        this->m_text.setCharacterSize(20);
        this->m_text.setFillColor(sf::Color::Black);
        this->m_text.setString("Ghesboro");

        auto size = this->m_text.getGlobalBounds();

        this->m_text.setOrigin(
            size.left + size.width / 2,
            size.top + size.height / 2);

        this->m_text.setPosition(g_window_cx, g_window_cy);
    }

    void
    TitleState::enter()
    {
        this->set_status(1);

        printf("<title-enter>\n");
    }

    void
    TitleState::leave()
    {
        printf("<title-leave>\n");
    }

    bool
    TitleState::attach()
    {
        printf("<title-attach>\n");

        return true;
    }

    void
    TitleState::detach()
    {
        printf("<title-detach>\n");
    }

    ma::u16
    TitleState::handle(const sf::Event& event)
    {
        if ( event.type == sf::Event::Closed )
            return this->status();

        if ( event.type == sf::Event::KeyReleased ) {
            if ( event.key.code == sf::Keyboard::Escape )
                return this->status();
        }

        return 0;
    }

    void
    TitleState::update(float delta)
    { }

    void
    TitleState::render(sf::RenderTarget& target)
    {
        target.draw(this->m_text);
    }
} // namespace fz
