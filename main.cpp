#include <SFML/Graphics.hpp>
#include "button.h"

int main()
{
    const float windowWidth = 1600;
    const float windowHeight = 900;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");

    Button button(200, 100, "hello world"); // red button
    button.setPosition(windowWidth - 200, 3 * ((windowWidth - 200) / 14));
    button.setColors(sf::Color::Red, sf::Color::Yellow);

    sf::VertexArray lines(sf::Lines, 56);
    float step = (windowWidth - 200) / 14;
    for (int i = 0; i < lines.getVertexCount(); i += 4, step += (windowWidth - 200) / 14) {
        /* set vertical line */
        lines[i].position = sf::Vector2f(step, 0);
        lines[i].color = sf::Color{ 0x373737FF };
        lines[i + 1].position = sf::Vector2f(step, windowHeight);
        lines[i + 1].color = sf::Color{ 0x373737FF };
        /* set horizontal line */
        lines[i + 2].position = sf::Vector2f(0, step);
        lines[i + 2].color = sf::Color{ 0x373737FF };
        lines[i + 3].position = sf::Vector2f(windowWidth - 200, step);
        lines[i + 3].color = sf::Color{ 0x373737FF };
    }
    
    lines[18].color = sf::Color::White;
    lines[19].color = sf::Color::White;
    lines[24].color = sf::Color::White;
    lines[25].color = sf::Color::White;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) // main loop
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) { // key pressed handler
                switch (event.key.code) {
                    case (sf::Keyboard::Escape):
                        window.close();
                        break;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) { // mouse button handler
                float mouseX = static_cast<float>(sf::Mouse::getPosition(window).x);
                float mouseY = static_cast<float>(sf::Mouse::getPosition(window).y);
                if (button.getGlobalBounds().contains(mouseX, mouseY)) { // if mouse in first button sprite
                    button.setOutline();
                    break;
                } 
            }
            if (event.type == sf::Event::MouseButtonReleased) { // calls everytime :(
                //std::cout << "Mouse released\n";
                button.removeOutline();
            }
        }
        window.clear();
        window.draw(lines);
        window.draw(button);
        window.display();
    }
    return 0;
}