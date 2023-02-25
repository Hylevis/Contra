#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include"Player.h"

using namespace std;

class Enemy
{
public:
	sf::Sprite m_Sprite;
	sf::Texture m_Standing_Texture;
	sf::Sprite m_Standing_Sprite;
	sf::Texture m_Prone_Texture;
	sf::Sprite m_Prone_Sprite;
	sf::Sprite m_Jumping_Sprite;
	sf::Texture m_Jumping_Texture;
	sf::Clock m_Shoot_CD;
	sf::Clock m_Jump_CD;
	bool m_Is_Prone = false;
	bool m_Is_Dead = false;
	bool m_Can_Jump = true;
	bool m_Is_Flipped = false;
	float m_velocityX = 0;
	float m_velocityY = 0;
	float m_accelerationX = 0;
	float m_accelerationY = 0;

	Enemy();
	void Enemy_Shoot(vector<Bullet*>& bullet_Position, bool is_Prone, bool is_Jumping, Player player1, bool is_Swimming);
	void Move_Enemy(float ground_Height);
};


