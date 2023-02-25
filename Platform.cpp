#include "Platform.h"

Platform::Platform(sf::Vector2f size, sf::Color color)
{
	m_Shape = sf::RectangleShape(size);
	m_Shape.setFillColor(color);
	m_Color = color;
}

Platform::Platform(sf::Vector2f size, sf::Color color, bool is_Destructable)
{
	m_Shape = sf::RectangleShape(size);
	m_Shape.setFillColor(color);
	m_Color = color;
	m_is_Destructable = is_Destructable;
}

