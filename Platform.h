#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <string>
#include <iostream>
#include "Player.h"
#include "Bullet.h"

#pragma once

using namespace std;

class Platform
{
public:
	sf::RectangleShape m_Shape;
	sf::Color m_Color;
	bool m_is_Destructable = false;
	bool m_Stepped_On = false;
	bool m_Timer_Started = false;
	bool m_Is_End = false;
	sf::Clock m_Fall_Timer;
	Platform(sf::Vector2f size, sf::Color color);
	Platform(sf::Vector2f size, sf::Color color, bool is_Destructable);
};

