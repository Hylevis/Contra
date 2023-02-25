#include "Enemy.h"
#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"

using namespace std;

Enemy::Enemy()
{
	if (!m_Standing_Texture.loadFromFile("Player.png", sf::IntRect(720, 0, 270, 450)))
	{
		sf::Sprite error_Sprite;
		error_Sprite.setColor(sf::Color::Magenta);
		m_Sprite = error_Sprite;
	}
	else
	{
		m_Standing_Texture.setSmooth(true);
		m_Sprite.setTexture(m_Standing_Texture);
		m_Standing_Sprite = sf::Sprite(m_Standing_Texture);
		m_Standing_Sprite.scale(.25, .25);
		m_Sprite.setOrigin(m_Standing_Texture.getSize().x / 2, m_Standing_Texture.getSize().y / 2);
		m_Sprite.scale(.25, .25);

	}

	if (!m_Prone_Texture.loadFromFile("animationsprites.png", sf::IntRect(210, 0, 190, 45)))
	{
		sf::Sprite error_Sprite;
		error_Sprite.setColor(sf::Color::Magenta);
		m_Sprite = error_Sprite;
	}
	else
	{
		m_Prone_Texture.setSmooth(true);
		m_Sprite.setTexture(m_Prone_Texture);
		m_Prone_Sprite = sf::Sprite(m_Prone_Texture);
		m_Prone_Sprite.scale(-2, 2);
		m_Prone_Sprite.setOrigin(m_Prone_Texture.getSize().x / 2, 0);

	}

	if (!m_Jumping_Texture.loadFromFile("animationsprites.png", sf::IntRect(0, 50, 30, 25)))
	{
		sf::Sprite error_Sprite;
		error_Sprite.setColor(sf::Color::Magenta);
		m_Sprite = error_Sprite;
	}
	else
	{
		m_Jumping_Texture.setSmooth(true);
		m_Sprite.setTexture(m_Jumping_Texture);
		m_Jumping_Sprite = sf::Sprite(m_Jumping_Texture);
		m_Jumping_Sprite.scale(2, 2);
		m_Jumping_Sprite.setOrigin(m_Jumping_Texture.getSize().x / 2, m_Jumping_Texture.getSize().y / 2);

	}
	//m_Sprite = sf::Sprite(m_Standing_Texture);

}

void Enemy::Move_Enemy(float ground_Height)
{

	float gravity = .5;

	if (m_Sprite.getPosition().y < ground_Height && m_velocityY < 20)                  //If you are above ground
		m_velocityY += gravity;    //Add gravity
	//else if (m_Sprite.getPosition().y > ground_Height && m_Is_Prone == false)             //If you are below ground
		//m_Sprite.setPosition(m_Sprite.getPosition().x, ground_Height);                 //That's not supposed to happen, put him back up

	m_velocityX += m_accelerationX;
	m_velocityY += m_accelerationY;

	m_Sprite.setPosition(m_Sprite.getPosition().x + m_velocityX, m_Sprite.getPosition().y);
	m_Sprite.setPosition(m_Sprite.getPosition().x, m_Sprite.getPosition().y + m_velocityY);

}

void Enemy::Enemy_Shoot(vector<Bullet*>& bullet_Position, bool is_Prone, bool is_Jumping, Player player1, bool is_Swimming)
{
	sf::Vector2f mousePositionFloat;
	Bullet* new_Proj = new Bullet;
	new_Proj->m_Sprite.setPosition(m_Sprite.getPosition().x - 30, m_Sprite.getPosition().y+30);

	if (is_Prone)
	{
		mousePositionFloat = sf::Vector2f(player1.m_Prone_Hit_Box.getPosition().x - 10, player1.m_Prone_Hit_Box.getPosition().y + 15);
	}
	else if (is_Jumping)
	{
		mousePositionFloat = sf::Vector2f(player1.m_Jumping_Hit_Box.getPosition().x, player1.m_Jumping_Hit_Box.getPosition().y);
	}
	else if (is_Swimming)
	{
		mousePositionFloat = sf::Vector2f(player1.m_Jumping_Hit_Box.getPosition().x-25, player1.m_Jumping_Hit_Box.getPosition().y);
	}
	else
	{
		mousePositionFloat = sf::Vector2f(player1.m_Standing_Hit_Box.getPosition().x, player1.m_Standing_Hit_Box.getPosition().y+3);
	}

	new_Proj->m_Direction = mousePositionFloat - new_Proj->m_Sprite.getPosition();

	new_Proj->m_Magnitude = sqrt((new_Proj->m_Direction.x * new_Proj->m_Direction.x + new_Proj->m_Direction.y * new_Proj->m_Direction.y));
	new_Proj->m_Direction.x = new_Proj->m_Direction.x / new_Proj->m_Magnitude;
	new_Proj->m_Direction.y = new_Proj->m_Direction.y / new_Proj->m_Magnitude;
	bullet_Position.push_back(new_Proj);
	m_Shoot_CD.restart();
}

