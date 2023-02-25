#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <string>
#include <iostream>
#include "Player.h"


class MainMenu
{
public:
	sf::Sprite m_Background_Sprite;
	sf::Texture m_Background_Texture;

	sf::RectangleShape m_Start_Button;

	MainMenu();
};

