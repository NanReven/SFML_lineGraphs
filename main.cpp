#include <SFML/Graphics.hpp>
#include "button.h"
#include "axis.h"

int main()
{
    const int windowWidth = 1400;
    const int windowHeight = 800;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");

    Button button(200, 100, "hello world"); // red button
    button.setPosition(200, 100);
    button.setColors(sf::Color::Red, sf::Color::Yellow);

    Axis axisLines(window);

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
        window.draw(axisLines);
        window.draw(button);
        window.display();
    }
    return 0;
}