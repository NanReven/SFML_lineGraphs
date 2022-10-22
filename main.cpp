#include <SFML/Graphics.hpp>
#include "button.h"

int main()
{
    const float windowWidth = 1400;
    const float windowHeight = 800;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");

    Button button(200, 100, "hello world"); // red button
    button.setPosition(200, 100);
    button.setColors(sf::Color::Red, sf::Color::Yellow);

    sf::VertexArray lines(sf::Lines, 40);
    float widthStep = windowWidth / 10;
    float heightStep = windowHeight / 10;
    for (int i = 0; i < 40; i += 4) {
        /* set vertical line */
        std::cout << widthStep << " : " << heightStep << std::endl;
        lines[i].position = sf::Vector2f(widthStep, 0);
        lines[i].color = sf::Color::Blue;
        lines[i + 1].position = sf::Vector2f(widthStep, windowHeight);
        lines[i + 1].color = sf::Color::Blue;
        /* set horizontal line */
        lines[i + 2].position = sf::Vector2f(0, heightStep);
        lines[i + 2].color = sf::Color::Blue;
        lines[i + 3].position = sf::Vector2f(windowWidth, heightStep);
        lines[i + 3].color = sf::Color::Blue;
        widthStep += windowWidth / 10;
        heightStep += windowHeight / 10;
    }
    for (int i = 16; i <= 19; i++)
        lines[i].color = sf::Color::White;

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