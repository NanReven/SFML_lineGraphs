#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#ifndef BUTTON_H
#define BUTTON_H

class Button : public sf::Drawable
{
private:
	sf::RectangleShape rectangle;
	float m_height; 
	float m_width;  
	sf::Font font;
	sf::Text m_label; 

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(rectangle, states);
		target.draw(m_label, states);
	}

public:
	~Button() {};

	Button(float width, float height) : m_width(width), m_height(height)
	{
		rectangle.setSize(sf::Vector2f(m_width, m_height));
	}

	Button(float width, float height, const std::string& label) : m_width(width), m_height(height)
	{
		rectangle.setSize(sf::Vector2f(m_width, m_height));
		if (!font.loadFromFile("src/arial.ttf"))
		{
			std::cout << "Couldn`t load font file\n";
			return;
		}
		m_label.setFont(font);
		m_label.setCharacterSize(20);
		m_label.setString(label);
	}

	void setColors(sf::Color buttonColor, sf::Color labelColor)
	{
		rectangle.setFillColor(buttonColor);
		m_label.setFillColor(labelColor);
	}

	void setLabel(const std::string& label)
	{
		if (!font.loadFromFile("src/arial.ttf"))
		{
			return;
		}
		m_label.setFont(font);
		m_label.setCharacterSize(20);
		m_label.setString(label);
	}

	void setPosition(float x, float y)
	{
		rectangle.setPosition(sf::Vector2f(x, y));
		m_label.setPosition(x + m_width / 4, y + m_height / 4);
	}
};

#endif
