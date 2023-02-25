#include "Background.h"

Background::Background()
{
	if (!m_Background_Texture.loadFromFile("Background.jpg"))
	{
		sf::Sprite error_Sprite;
		error_Sprite.setColor(sf::Color::Magenta);
		m_Background_Sprite = error_Sprite;
	}
	else
	{
		m_Background_Texture.setSmooth(true);
		m_Background_Sprite.setTexture(m_Background_Texture);
		m_Background_Sprite.scale(10, 5);
	}
}