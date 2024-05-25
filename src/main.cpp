#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow{ { 800u, 600u }, "BlockBreaker3000" };
    window.setFramerateLimit(144);

    sf::Text text;

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        window.close();
    }

    // select the font
    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString("Hello world in BlockBreaker3000");

    // set the character size
    text.setCharacterSize(24); // in pixels, not points!

    // set the color
    text.setFillColor(sf::Color::Red);

    // set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    sf::RectangleShape racket(sf::Vector2f(120.f, 20.f));
    racket.setFillColor(sf::Color(100, 250, 50));
    float position_x = 340;
    float position_y = 550;
    racket.setPosition(position_x, position_y);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Left)
                {
                    position_x -= 10;
                    racket.setPosition(position_x, position_y);
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    position_x += 10;
                    racket.setPosition(position_x, position_y);
                }
                break;
            default:
                break;
            }
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        

        window.clear(sf::Color::Black);
        // inside the main loop, between window.clear() and window.display()
        window.draw(text);
        window.draw(racket);
        window.display();
    }
}