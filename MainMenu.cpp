#include "MainMenu.h"

MainMenu::MainMenu()
{
	if (!m_Background_Texture.loadFromFile("MainMenu.jpg"))
	{
		sf::Sprite error_Sprite;
		error_Sprite.setColor(sf::Color::Magenta);
		m_Background_Sprite = error_Sprite;
	}
	else
	{
		m_Background_Texture.setSmooth(true);
		m_Background_Sprite.setTexture(m_Background_Texture);
		m_Background_Sprite.scale(1.2, 2.3);
	}

	m_Start_Button.setSize(sf::Vector2f(250,50));
	m_Start_Button.setFillColor(sf::Color::Red);
	m_Start_Button.setPosition(150, 550);
}