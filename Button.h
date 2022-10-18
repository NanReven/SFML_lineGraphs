#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#ifndef BUTTON_H
#define BUTTON_H

class Button
{
private:
	sf::RectangleShape rectangle;
	float m_height; //
	float m_width; // 
	sf::Text m_label; //
public:
	Button(float height, float width) : m_height(height), m_width(width)
	{
		rectangle.setSize(sf::Vector2f(m_height, m_width));
		m_label.setPosition(m_height, m_width); // ?????
	}

	Button(float height, float width, const std::string& label) : m_height(height), m_width(width)
	{
		rectangle.setSize(sf::Vector2f(m_height, m_width));
		sf::Font font;
		if (!font.loadFromFile("src/arial.ttf"))
		{
			return;
		}
		m_label.setFont(font);
		m_label.setCharacterSize(24);
		m_label.setString(label);
		m_label.setPosition(m_height, m_width); // ?????
	}

	void setColors(sf::Color buttonColor, sf::Color labelColor)
	{
		rectangle.setFillColor(buttonColor);
		m_label.setFillColor(labelColor);
	}

	void setLabel(const std::string& label, sf::Color labelColor)
	{
		sf::Font font;
		if (!font.loadFromFile("src/arial.ttf"))
		{
			return;
		}
		m_label.setFont(font);
		m_label.setCharacterSize(24);
		m_label.setFillColor(labelColor);
		m_label.setString(label);
	}

	sf::RectangleShape& get_button() 
	{
		return rectangle;
	}
};

#endif
