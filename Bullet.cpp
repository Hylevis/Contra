#include "Bullet.h"


Bullet::Bullet()
{
	if (!m_Texture.loadFromFile("bullet.png"))
	{
		sf::Sprite error_Sprite;
		error_Sprite.setColor(sf::Color::Magenta);
		m_Sprite = error_Sprite;
	}
	else
	{
		m_Texture.setSmooth(true);
		m_Sprite.setTexture(m_Texture);
		m_Sprite.scale(.05, .05);
		m_Hitbox.setFillColor(sf::Color::Red);
		m_Hitbox.setRadius(5);
	}
}

void Bullet::Rotate_Bullet(Bullet* bullet, sf::RenderWindow& win)
{
	sf::Vector2f curPos = bullet->m_Sprite.getPosition();
	sf::Vector2i position = sf::Mouse::getPosition(win);


	const float PI = 3.14159265;

	float dx = curPos.x - position.x;
	float dy = curPos.y - position.y;

	float rotation = (atan2(dy, dx)) * 180 / PI;

	bullet->m_Sprite.setRotation(rotation + 180);
}

void Bullet::Move_Bullet()
{

	/*m_velocityX += m_accelerationX;
	m_velocityY += m_accelerationY;

	m_Sprite.setPosition(m_Sprite.getPosition().x + m_velocityX, m_Sprite.getPosition().y);
	m_Sprite.setPosition(m_Sprite.getPosition().x, m_Sprite.getPosition().y + m_velocityY);
	*/
	m_Sprite.move(m_Direction.x * 16, m_Direction.y * 16);
}

void Bullet::Update_Bullets(vector<Bullet*>& bullet_Position, sf::RenderWindow& window, int i, Player& player)
{

		if (bullet_Position[i]->m_Sprite.getPosition().x < 50 || bullet_Position[i]->m_Sprite.getPosition().x > player.m_Sprite.getPosition().x + 800)
		{
			delete bullet_Position[i];
			bullet_Position.erase(bullet_Position.begin() + i);

		}
		else
		{
			bullet_Position[i]->Move_Bullet();
			bullet_Position[i]->m_Hitbox.setPosition(bullet_Position[i]->m_Sprite.getPosition().x + 3, bullet_Position[i]->m_Sprite.getPosition().y + 1);
			window.draw(bullet_Position[i]->m_Sprite);
			//window.draw(bullet_Position[i]->m_Hitbox);
		}

}