#pragma once
#include <SFML/Graphics.hpp>

using namespace std;

class Player
{
public:
	sf::Sprite m_Sprite;
	sf::Texture m_Standing_Texture;
	sf::Texture m_Running_Texture_1;
	sf::Texture m_Running_Texture_2;
	sf::Texture m_Running_Texture_3;
	sf::Texture m_Running_Texture_4;
	sf::Sprite m_Running_Sprite;
	sf::Sprite m_Running_Sprite_1;
	sf::Sprite m_Running_Sprite_2;
	sf::Sprite m_Running_Sprite_3;
	sf::Sprite m_Running_Sprite_4;
	sf::Sprite m_Standing_Sprite;
	sf::Texture m_Prone_Texture;
	sf::Sprite m_Prone_Sprite;
	sf::Sprite m_Jumping_Sprite;
	sf::Texture m_Jumping_Texture;
	sf::Texture m_Swimming_Texture;
	sf::Sprite m_Swimming_Sprite;
	sf::RectangleShape m_Standing_Hit_Box;
	sf::RectangleShape m_Running_Hit_Box;
	sf::RectangleShape m_Jumping_Hit_Box;
	sf::RectangleShape m_Prone_Hit_Box;
	sf::RectangleShape m_Current_Hit_Box;
	sf::RectangleShape m_Swimming_Hit_Box;



	bool m_Is_Jumping = false;
	bool m_Can_Jump = true;
	bool m_Is_Prone = false;
	bool m_Is_Swimming = false;
	bool m_Is_Falling = false;
	bool m_Is_Running = false;
	float m_velocityX = 0;
	float m_velocityY = 0;
	float m_accelerationX = 0;
	float m_accelerationY = 0;

	Player();
	void Move_Player(float ground_Height);
};

