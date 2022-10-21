#pragma once
#ifndef AXIS_H
#define AXIS_H

#include <SFML/Graphics.hpp>

class Axis : public sf::Drawable
{
private:
    sf::VertexArray axisLines;
    sf::VertexArray additionalLines;

    void setAxisLines(sf::RenderTarget& target);
    void setAdditionalLines(sf::RenderTarget& target);
    void setLines(sf::RenderTarget& target);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    Axis(sf::RenderTarget& target);
};

#endif AXIS_H