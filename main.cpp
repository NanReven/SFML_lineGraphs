#include <SFML/Graphics.hpp>
#include "Button.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1400, 800), "SFML works!");
    Button button(200, 100, "hello world");
    button.setPosition(200, 100);
    button.setColors(sf::Color::Red, sf::Color::Yellow);
    Button secondButton(300, 150);
    secondButton.setPosition(700, 400);
    secondButton.setLabel("Yo is that work???");
    secondButton.setColors(sf::Color::Blue, sf::Color::Yellow);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                case (sf::Keyboard::Escape):
                    window.close();
                    break;
                }
            }
        }
        window.clear();
        window.draw(button);
        window.draw(secondButton);
        window.display();
    }
    return 0;
}