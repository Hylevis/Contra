#include "Player.h"

Player::Player()
{
	if (!m_Standing_Texture.loadFromFile("Player.png", sf::IntRect(0, 0, 270, 450)))
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
		m_Standing_Hit_Box.setFillColor(sf::Color::Red);
		m_Standing_Hit_Box.setSize(sf::Vector2f(15,60));
		m_Standing_Hit_Box.setOrigin(m_Standing_Hit_Box.getSize().x / 2, m_Standing_Hit_Box.getSize().y / 2);
		m_Standing_Hit_Box.setPosition(m_Standing_Sprite.getPosition());

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
		m_Prone_Sprite.scale(2, 2);
		m_Prone_Sprite.setOrigin(m_Prone_Texture.getSize().x / 2, 0);
		m_Prone_Hit_Box.setFillColor(sf::Color::Red);
		m_Prone_Hit_Box.setSize(sf::Vector2f(90, 10));
		m_Prone_Hit_Box.setPosition(m_Standing_Sprite.getPosition());

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
		m_Jumping_Hit_Box.setFillColor(sf::Color::Red);
		m_Jumping_Hit_Box.setSize(sf::Vector2f(20, 20));
		m_Jumping_Hit_Box.setPosition(m_Standing_Sprite.getPosition());

	}

	if (!m_Swimming_Texture.loadFromFile("animationsprites.png", sf::IntRect(150, 280, 30, 25)))
	{
		sf::Sprite error_Sprite;
		error_Sprite.setColor(sf::Color::Magenta);
		m_Sprite = error_Sprite;
	}
	else
	{
		m_Swimming_Texture.setSmooth(true);
		m_Sprite.setTexture(m_Swimming_Texture);
		m_Swimming_Sprite = sf::Sprite(m_Swimming_Texture);
		m_Swimming_Sprite.scale(2, 2);
		m_Swimming_Sprite.setOrigin(m_Swimming_Texture.getSize().x / 2, m_Swimming_Texture.getSize().y / 2);
		m_Swimming_Hit_Box.setFillColor(sf::Color::Red);
		m_Swimming_Hit_Box.setSize(sf::Vector2f(20, 30));
		m_Swimming_Hit_Box.setPosition(m_Standing_Sprite.getPosition());

	}
	if (!m_Running_Texture_1.loadFromFile("animationsprites.png", sf::IntRect(0, 75, 30, 50)))
	{
		sf::Sprite error_Sprite;
		error_Sprite.setColor(sf::Color::Magenta);
		m_Sprite = error_Sprite;
	}
	else
	{
		m_Running_Texture_1.setSmooth(true);
		m_Sprite.setTexture(m_Running_Texture_1);
		m_Running_Sprite_1 = sf::Sprite(m_Running_Texture_1);
		m_Running_Sprite_1.scale(2, 2);
		m_Running_Sprite_1.setOrigin(m_Running_Texture_1.getSize().x / 2,0);


	}

	if (!m_Running_Texture_2.loadFromFile("animationsprites.png", sf::IntRect(40, 75, 30, 50)))
	{
		sf::Sprite error_Sprite;
		error_Sprite.setColor(sf::Color::Magenta);
		m_Sprite = error_Sprite;
	}
	else
	{
		m_Running_Texture_2.setSmooth(true);
		m_Sprite.setTexture(m_Running_Texture_2);
		m_Running_Sprite_2 = sf::Sprite(m_Running_Texture_2);
		m_Running_Sprite_2.scale(2, 2);
		m_Running_Sprite_2.setOrigin(m_Running_Texture_2.getSize().x / 2, 0);


	}

	if (!m_Running_Texture_3.loadFromFile("animationsprites.png", sf::IntRect(75, 75, 30, 50)))
	{
		sf::Sprite error_Sprite;
		error_Sprite.setColor(sf::Color::Magenta);
		m_Sprite = error_Sprite;
	}
	else
	{
		m_Running_Texture_3.setSmooth(true);
		m_Sprite.setTexture(m_Running_Texture_2);
		m_Running_Sprite_3 = sf::Sprite(m_Running_Texture_3);
		m_Running_Sprite_3.scale(2, 2);
		m_Running_Sprite_3.setOrigin(m_Running_Texture_3.getSize().x / 2, 0);


	}
	if (!m_Running_Texture_4.loadFromFile("animationsprites.png", sf::IntRect(115, 75, 30, 50)))
	{
		sf::Sprite error_Sprite;
		error_Sprite.setColor(sf::Color::Magenta);
		m_Sprite = error_Sprite;
	}
	else
	{
		m_Running_Texture_4.setSmooth(true);
		m_Sprite.setTexture(m_Running_Texture_4);
		m_Running_Sprite_4 = sf::Sprite(m_Running_Texture_4);
		m_Running_Sprite_4.scale(2, 2);
		m_Running_Sprite_4.setOrigin(m_Running_Texture_4.getSize().x / 2, 0);


	}
	m_Running_Hit_Box.setFillColor(sf::Color::Red);
	m_Running_Hit_Box.setSize(sf::Vector2f(15, 60));
	m_Running_Hit_Box.setOrigin(m_Running_Texture_1.getSize().x / 2, m_Running_Texture_1.getSize().y / 2);
	m_Running_Hit_Box.setPosition(m_Running_Sprite.getPosition());
}

void Player::Move_Player(float ground_Height)
{

	float gravity = .5;

	if (m_Sprite.getPosition().y < ground_Height && m_velocityY < 20)                  //If you are above ground
		m_velocityY += gravity;    //Add gravity
	//else if (m_Sprite.getPosition().y > 412)             //If you are below ground
	//	m_Sprite.setPosition(m_Sprite.getPosition().x,412);                 //That's not supposed to happen, put him back up

	m_velocityX += m_accelerationX;
	m_velocityY += m_accelerationY;

	m_Sprite.setPosition(m_Sprite.getPosition().x + m_velocityX, m_Sprite.getPosition().y);
	m_Sprite.setPosition(m_Sprite.getPosition().x, m_Sprite.getPosition().y + m_velocityY);

}