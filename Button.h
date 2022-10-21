#pragma once

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Button : public sf::Drawable
{
private:
	sf::RectangleShape rectangle;
	float m_height; 
	float m_width;  
	sf::Font font;
	sf::Text m_label; 

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Button(float width, float height);
	Button(float width, float height, const std::string& label);
	void setColors(sf::Color buttonColor, sf::Color labelColor);
	void setLabel(const std::string& label);
	void setPosition(float x, float y);
	void setOutline();
	void removeOutline();
	sf::FloatRect getGlobalBounds() const;
};

#endif