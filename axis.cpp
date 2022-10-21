#include "axis.h"

void Axis::setAxisLines(sf::RenderTarget& target)
{
    const float windowWidth = static_cast<float>(target.getSize().x);
    const float windowHeight = static_cast<float>(target.getSize().y);
    axisLines[0].position = sf::Vector2f(windowWidth / 2, 0);
    axisLines[1].position = sf::Vector2f(windowWidth / 2, windowHeight);
    axisLines[2].position = sf::Vector2f(0, windowHeight / 2);
    axisLines[3].position = sf::Vector2f(windowWidth, windowHeight / 2);
}
        
void Axis::setAdditionalLines(sf::RenderTarget& target)
{
    const float windowWidth = static_cast<float>(target.getSize().x);
    const float windowHeight = static_cast<float>(target.getSize().y);
    float widthStep = windowWidth / 10;
    float heightStep = windowHeight / 10;
    for (int i = 0; i < (int)additionalLines.getVertexCount(); i += 4) {
        /* set vertical line */
        additionalLines[i].position = sf::Vector2f(widthStep, 0);
        additionalLines[i].color = sf::Color::Blue;
        additionalLines[i + 1].position = sf::Vector2f(widthStep, windowHeight);
        additionalLines[i + 1].color = sf::Color::Blue;
        /* set horizontal line */
        additionalLines[i + 2].position = sf::Vector2f(0, heightStep);
        additionalLines[i + 2].color = sf::Color::Blue;
        additionalLines[i + 3].position = sf::Vector2f(windowWidth, heightStep);
        additionalLines[i + 3].color = sf::Color::Blue;
        widthStep += widthStep;
        heightStep += heightStep;
    }
}

void Axis::setLines(sf::RenderTarget& target)
{
    setAxisLines(target);
    setAdditionalLines(target);
}

void Axis::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(additionalLines, states);
    target.draw(axisLines, states);
}


Axis::Axis(sf::RenderTarget& target) : axisLines(sf::Lines, 4), additionalLines(sf::Lines, 40)
{
    setLines(target);
}