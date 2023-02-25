#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include "Player.h"
#pragma once

using namespace std;
class Bullet
{
public:
	sf::Sprite m_Sprite;
	sf::Texture m_Texture;
	sf::Vector2f m_Direction;
	sf::CircleShape m_Hitbox;
	float m_velocityX = 0;
	float m_velocityY = 0;
	float m_accelerationX = 0;
	float m_accelerationY = 0;
	float m_Magnitude = 0;
	Bullet();
	void Rotate_Bullet(Bullet* bullet, sf::RenderWindow& win);
	void Move_Bullet();
	void Update_Bullets(vector<Bullet*>& bullet_Position, sf::RenderWindow& window, int i, Player& player);

};


