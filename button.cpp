#include "button.h"

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rectangle, states);
	target.draw(m_label, states);
}

Button::Button(float width, float height) : m_width(width), m_height(height)
{
	rectangle.setSize(sf::Vector2f(m_width, m_height));
}

Button::Button(float width, float height, const std::string& label) : m_width(width), m_height(height)
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

void Button::setColors(sf::Color buttonColor, sf::Color labelColor)
{
	rectangle.setFillColor(buttonColor);
	m_label.setFillColor(labelColor);
}

void Button::setLabel(const std::string& label)
{
	if (!font.loadFromFile("src/arial.ttf"))
	{
		return;
	}
	m_label.setFont(font);
	m_label.setCharacterSize(20);
	m_label.setString(label);
}

void Button::setPosition(float x, float y)
{
	rectangle.setPosition(sf::Vector2f(x, y));
	m_label.setPosition(x + m_width / 4, y + m_height / 4);
}

void Button::setOutline()
{
	rectangle.setOutlineThickness(3);
	rectangle.setOutlineColor(sf::Color::White);
}

void Button::removeOutline()
{
	rectangle.setOutlineThickness(0);
}

sf::FloatRect Button::getGlobalBounds() const
{
	return rectangle.getGlobalBounds();
}