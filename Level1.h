#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <string>
#include <iostream>
#include "Player.h"
#include "Bullet.h"
#include "Platform.h"

#pragma once

using namespace std;

class Level1
{
public:
	vector<Platform> m_Platforms;
	vector<Platform> m_Destructible_Platforms;
	vector<Enemy*> m_Enemies;
	//sf::RectangleShape m_Platform;

	Level1();
	void Enemy_AI(int enemy_Ground_Height, bool is_Jumping, bool is_Prone, sf::RenderWindow& window, vector<Bullet*>& enemies_bullet_Position, vector<Bullet*>& bullet_Position, Player& player1, int i, bool is_Swimming);
	void Colision(Player& player1, int& ground_Height, sf::Clock fall_Timer);
};

class Level2
{
public:
	vector<Platform> m_Platforms;
	vector<Platform> m_Destructible_Platforms;
	vector<Enemy*> m_Enemies;
	//sf::RectangleShape m_Platform;

	Level2();
	void Enemy_AI(int enemy_Ground_Height, int ground_Height, bool is_Jumping, bool is_Prone, sf::RenderWindow& window, vector<Bullet*>& enemies_bullet_Position, vector<Bullet*>& bullet_Position, Player& player1, int i, bool is_Swimming);
	void Colision(Player& player1, int& ground_Height, sf::Clock fall_Timer);
};


