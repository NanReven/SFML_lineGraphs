#pragma once
#ifndef AXIS_H
#define AXIS_H

#include <SFML/Graphics.hpp>

class Axis : public sf::Drawable
{
private:
	const float width;
	const float height;
	const float increment;
	int perimeter;
	int vertexes;
	sf::VertexArray axis;
	void setAxis()
	{
		float step = increment;
		int i = 0;
		while (i < 20) { //asdkhqdwdwlwdkd.
			/* set horizontal line */
			axis[i].position = sf::Vector2f(0, step);
			axis[i].color = sf::Color{ 0x373737FF };
			axis[i + 1].position = sf::Vector2f(width, step);
			axis[i + 1].color = sf::Color{ 0x373737FF };
			i += 2;
			step += increment;
		}
		step = increment;
		while (i < 64) {
			axis[i].position = sf::Vector2f(step, 0);
			axis[i].color = sf::Color{ 0x373737FF };
			axis[i + 1].position = sf::Vector2f(step, height);
			axis[i + 1].color = sf::Color{ 0x373737FF };
			i += 2;
			step += increment;
		}
		axis[18].color = sf::Color::White;
		axis[19].color = sf::Color::White;
		axis[24].color = sf::Color::White;
		axis[25].color = sf::Color::White;
	}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(axis, states);
	}
public:
	Axis(float windowWidth, float windowHeight, float bottomSize, int horizontalLines) :
		width(windowWidth), height(windowHeight - bottomSize), 
		increment(height / horizontalLines), perimeter((width + height) * 2),
		vertexes(perimeter / increment),
		axis(sf::Lines, vertexes - vertexes % 4)
	{
		setAxis();
	}
};

#endif
