#include "Level1.h"


Level1::Level1()
{
    
    Platform platform(sf::Vector2f(4000.f, 50.f), sf::Color::Green);
    platform.m_Shape.setPosition(400, 490);
    m_Platforms.push_back(platform);

    Platform platform2(sf::Vector2f(300.f, 50.f), sf::Color::Green);
    platform2.m_Shape.setPosition(800, 690);
    m_Platforms.push_back(platform2);

    Platform platform3(sf::Vector2f(150.f, 50.f), sf::Color::Green);
    platform3.m_Shape.setPosition(1200, 850);
    m_Platforms.push_back(platform3);

    Platform platform4(sf::Vector2f(300.f, 50.f), sf::Color::Green);
    platform4.m_Shape.setPosition(1400, 1000);
    m_Platforms.push_back(platform4);

    Platform platform5(sf::Vector2f(300.f, 50.f), sf::Color::Green);
    platform5.m_Shape.setPosition(2000, 690);
    m_Platforms.push_back(platform5);

    Platform platform6(sf::Vector2f(150.f, 50.f), sf::Color::Green);
    platform6.m_Shape.setPosition(1750, 850);
    m_Platforms.push_back(platform6);

    Platform platform7(sf::Vector2f(300.f, 50.f), sf::Color::Green);
    platform7.m_Shape.setPosition(3500, 725);
    m_Platforms.push_back(platform7);

    Platform platform8(sf::Vector2f(200.f, 50.f), sf::Color::Green);
    platform8.m_Shape.setPosition(3300, 900);
    m_Platforms.push_back(platform8);

    Platform platform9(sf::Vector2f(10000.f, 500.f), sf::Color::Blue);
    platform9.m_Shape.setPosition(400, 1100);
    m_Platforms.push_back(platform9);


    Platform bridge1(sf::Vector2f(200.f, 50.f), sf::Color::White, true);
    bridge1.m_Shape.setPosition(4400, 490);
    m_Destructible_Platforms.push_back(bridge1);

    Platform bridge2(sf::Vector2f(200.f, 50.f), sf::Color::White, true);
    bridge2.m_Shape.setPosition(4600, 490);
    m_Destructible_Platforms.push_back(bridge2);

    Platform bridge3(sf::Vector2f(200.f, 50.f), sf::Color::White, true);
    bridge3.m_Shape.setPosition(4800, 490);
    m_Destructible_Platforms.push_back(bridge3);

    Platform platform10(sf::Vector2f(800.f, 50.f), sf::Color::Green);
    platform10.m_Shape.setPosition(5000, 490);
    m_Platforms.push_back(platform10);

    Platform bridge4(sf::Vector2f(200.f, 50.f), sf::Color::White, true);
    bridge4.m_Shape.setPosition(5800, 490);
    m_Destructible_Platforms.push_back(bridge4);

    Platform bridge5(sf::Vector2f(200.f, 50.f), sf::Color::White, true);
    bridge5.m_Shape.setPosition(6000, 490);
    m_Destructible_Platforms.push_back(bridge5);

    Platform bridge6(sf::Vector2f(200.f, 50.f), sf::Color::White, true);
    bridge6.m_Shape.setPosition(6200, 490);
    m_Destructible_Platforms.push_back(bridge6);

    Platform platform11(sf::Vector2f(1200.f, 50.f), sf::Color::Green);
    platform11.m_Shape.setPosition(6400, 490);
    m_Platforms.push_back(platform11);

    Platform platform12(sf::Vector2f(2200.f, 50.f), sf::Color::Green);
    platform12.m_Shape.setPosition(7400, 290);
    m_Platforms.push_back(platform12);

    Platform platform13(sf::Vector2f(400.f, 50.f), sf::Color::Green);
    platform13.m_Shape.setPosition(7400, 900);
    m_Platforms.push_back(platform13);

    Platform platform14(sf::Vector2f(300.f, 50.f), sf::Color::Green);
    platform14.m_Shape.setPosition(7700, 650);
    m_Platforms.push_back(platform14);

    Platform platform15(sf::Vector2f(1200.f, 50.f), sf::Color::Green);
    platform15.m_Shape.setPosition(8200, 650);
    m_Platforms.push_back(platform15);

    Platform platform16(sf::Vector2f(1200.f, 50.f), sf::Color::Green);
    platform16.m_Shape.setPosition(9500, 550);
    m_Platforms.push_back(platform16);

    Platform endFlag(sf::Vector2f(50.f, 1000.f), sf::Color::Red);
    endFlag.m_Shape.setPosition(10700, 0);
    endFlag.m_Is_End = true;
    m_Platforms.push_back(endFlag);

    Enemy* new_Enemy = new Enemy;
    new_Enemy->m_Sprite = new_Enemy->m_Standing_Sprite;
    new_Enemy->m_Sprite.setPosition(1200, 490);
    m_Enemies.push_back(new_Enemy);
    Enemy* new_Enemy2 = new Enemy;
    new_Enemy2->m_Sprite = new_Enemy2->m_Standing_Sprite;
    new_Enemy2->m_Sprite.setPosition(3400, 900);
    new_Enemy2->m_Can_Jump = false;
    m_Enemies.push_back(new_Enemy2);
    Enemy* new_Enemy3 = new Enemy;
    new_Enemy3->m_Sprite = new_Enemy3->m_Standing_Sprite;
    new_Enemy3->m_Sprite.setPosition(1500, 1000);
    new_Enemy3->m_Can_Jump = false;
    m_Enemies.push_back(new_Enemy3);

    Enemy* new_Enemy4 = new Enemy;
    new_Enemy4->m_Sprite = new_Enemy4->m_Prone_Sprite;
    new_Enemy4->m_Is_Prone = true;
    new_Enemy4->m_Sprite.setPosition(5400, 490);
    m_Enemies.push_back(new_Enemy4);

    Enemy* new_Enemy5 = new Enemy;
    new_Enemy5->m_Sprite = new_Enemy->m_Standing_Sprite;
    new_Enemy5->m_Sprite.setPosition(6800, 490);
    m_Enemies.push_back(new_Enemy5);

    Enemy* new_Enemy6 = new Enemy;
    new_Enemy6->m_Sprite = new_Enemy6->m_Standing_Sprite;
    new_Enemy6->m_Sprite.setPosition(7600, 900);
    new_Enemy6->m_Can_Jump = false;
    m_Enemies.push_back(new_Enemy6);

    Enemy* new_Enemy7 = new Enemy;
    new_Enemy7->m_Sprite = new_Enemy7->m_Standing_Sprite;
    new_Enemy7->m_Sprite.setPosition(7700, 290);
    m_Enemies.push_back(new_Enemy7);


}
void Level1::Colision(Player& player1, int& ground_Height, sf::Clock fall_Timer)
{
    for (int i = 0; i < m_Platforms.size(); i++)
    {

        if (player1.m_Sprite.getGlobalBounds().intersects(m_Platforms[i].m_Shape.getGlobalBounds()) && player1.m_Is_Jumping == false && player1.m_Is_Falling == false && m_Platforms[i].m_Is_End == false)
        {
            player1.m_Sprite.setPosition(player1.m_Sprite.getPosition().x, m_Platforms[i].m_Shape.getPosition().y - 78);
            player1.m_velocityY = 10;
            ground_Height = m_Platforms[i].m_Shape.getPosition().y - 78;
            
            //cout << player1.m_Sprite.getPosition().y << endl;
            //cout << ground_Height << endl;
        }
        else if (player1.m_Is_Falling == true)
        {
            if (fall_Timer.getElapsedTime().asSeconds() > .2)
            {

                player1.m_Is_Falling = false;
            }
        }

    }

    for (int i = 0; i < m_Destructible_Platforms.size(); i++)
    {

        if (m_Destructible_Platforms[i].m_Stepped_On == false)
        {
            m_Destructible_Platforms[i].m_Fall_Timer.restart();

        }
        if (player1.m_Sprite.getGlobalBounds().intersects(m_Destructible_Platforms[i].m_Shape.getGlobalBounds()) && player1.m_Is_Jumping == false && player1.m_Is_Falling == false)
        {
            m_Destructible_Platforms[i].m_Stepped_On = true;
            m_Destructible_Platforms[i].m_Shape.setFillColor(sf::Color::Red);
            player1.m_Sprite.setPosition(player1.m_Sprite.getPosition().x, m_Destructible_Platforms[i].m_Shape.getPosition().y - 78);
            player1.m_velocityY = 10;
            ground_Height = m_Destructible_Platforms[i].m_Shape.getPosition().y - 78;
        }
        else if (player1.m_Is_Falling == true)
        {
            if (fall_Timer.getElapsedTime().asSeconds() > .2)
            {
                player1.m_Is_Falling = false;
            }
        }

    }
}
void Level1::Enemy_AI(int enemy_Ground_Height, bool is_Jumping, bool is_Prone, sf::RenderWindow& window, vector<Bullet*>& enemies_bullet_Position, vector<Bullet*>& bullet_Position, Player& player1, int i, bool is_Swimming)
{
    
        for (int j = 0; j < m_Platforms.size(); j++)
        {
            if (m_Enemies[i]->m_Sprite.getGlobalBounds().intersects(m_Platforms[j].m_Shape.getGlobalBounds()) && m_Enemies[i]->m_Is_Prone == false)
            {
                m_Enemies[i]->m_Sprite.setPosition(m_Enemies[i]->m_Sprite.getPosition().x, m_Platforms[j].m_Shape.getPosition().y - 78);
                enemy_Ground_Height = m_Platforms[j].m_Shape.getPosition().y - 78;
            }
            else if (m_Enemies[i]->m_Sprite.getGlobalBounds().intersects(m_Platforms[j].m_Shape.getGlobalBounds()) && m_Enemies[i]->m_Is_Prone == true)
            {
                m_Enemies[i]->m_velocityY = 0;
                m_Enemies[i]->m_Sprite.setPosition(m_Enemies[i]->m_Sprite.getPosition().x, m_Platforms[j].m_Shape.getPosition().y - 40);
            }

        }
        if (m_Enemies[i]->m_Sprite.getPosition().y == enemy_Ground_Height)
        {

            if (rand() % 4 == 0 && m_Enemies[i]->m_Is_Prone == false && m_Enemies[i]->m_Can_Jump == true)
            {
                if (m_Enemies[i]->m_Jump_CD.getElapsedTime().asSeconds() > 4)
                {
                    m_Enemies[i]->m_velocityY = -20;
                    m_Enemies[i]->m_Jump_CD.restart();
                }
            }
        }
        
        if (rand() % 4 == 1)
        {
            if (m_Enemies[i]->m_Shoot_CD.getElapsedTime().asSeconds() > 1.5 && m_Enemies[i]->m_Sprite.getPosition().x < player1.m_Sprite.getPosition().x + 650 && m_Enemies[i]->m_Sprite.getPosition().x > player1.m_Sprite.getPosition().x - 650)
            {
                m_Enemies[i]->Enemy_Shoot(enemies_bullet_Position, is_Prone, is_Jumping, player1, is_Swimming);
            }
        }
        if (rand() % 4 == 2)
        {

            // new_Enemy->m_velocityY = -20;
             //new_Enemy->m_Direction = random_Vector - new_Enemy->m_Sprite.getPosition();
        }
        if (rand() % 4 == 3)
        {


            //new_Enemy->m_Direction = random_Vector - new_Enemy->m_Sprite.getPosition();
        }

        
        m_Enemies[i]->Move_Enemy(enemy_Ground_Height);

        window.draw(m_Enemies[i]->m_Sprite);
      
        if (m_Enemies[i]->m_Sprite.getPosition().x < player1.m_Sprite.getPosition().x && m_Enemies[i]->m_Sprite.getScale().x > 0)
        {
            if (m_Enemies[i]->m_Is_Prone == false)
            {
                m_Enemies[i]->m_Sprite.setScale(m_Enemies[i]->m_Sprite.getScale().x * -1, m_Enemies[i]->m_Sprite.getScale().y);
            }


        }
        else if (m_Enemies[i]->m_Sprite.getPosition().x < player1.m_Sprite.getPosition().x && m_Enemies[i]->m_Is_Prone == true && m_Enemies[i]->m_Sprite.getScale().x < 0)
        {
            m_Enemies[i]->m_Sprite.setScale(2, m_Enemies[i]->m_Sprite.getScale().y);
        }
        else if (m_Enemies[i]->m_Sprite.getPosition().x > player1.m_Sprite.getPosition().x && m_Enemies[i]->m_Is_Prone == true)
        {
            m_Enemies[i]->m_Sprite.setScale(-2, m_Enemies[i]->m_Sprite.getScale().y);
        }
        else if (m_Enemies[i]->m_Sprite.getPosition().x > player1.m_Sprite.getPosition().x && m_Enemies[i]->m_Sprite.getScale().x < 0)
        {
            if (m_Enemies[i]->m_Is_Prone == false)
            {
            m_Enemies[i]->m_Sprite.setScale(m_Enemies[i]->m_Sprite.getScale().x * -1, m_Enemies[i]->m_Sprite.getScale().y);
            }
        }
        
        for (int j = bullet_Position.size() - 1; j >= 0; j--)
        {
            if (bullet_Position[j]->m_Sprite.getGlobalBounds().intersects(m_Enemies[i]->m_Sprite.getGlobalBounds()) && m_Enemies[i]->m_Sprite.getGlobalBounds().intersects(bullet_Position[j]->m_Sprite.getGlobalBounds()))
            {
                delete bullet_Position[j];
                bullet_Position.erase(bullet_Position.begin() + j);
                m_Enemies[i]->m_Is_Dead = true;
            }
            
        }
        
}


Level2::Level2()
{

    Platform platform(sf::Vector2f(4000.f, 50.f), sf::Color::Green);
    platform.m_Shape.setPosition(400, 490);
    m_Platforms.push_back(platform);

    Platform platform2(sf::Vector2f(300.f, 50.f), sf::Color::Green);
    platform2.m_Shape.setPosition(800, 690);
    m_Platforms.push_back(platform2);

    Platform platform3(sf::Vector2f(150.f, 50.f), sf::Color::Green);
    platform3.m_Shape.setPosition(1200, 850);
    m_Platforms.push_back(platform3);

    Platform platform4(sf::Vector2f(300.f, 50.f), sf::Color::Green);
    platform4.m_Shape.setPosition(1400, 1000);
    m_Platforms.push_back(platform4);

    Platform platform5(sf::Vector2f(300.f, 50.f), sf::Color::Green);
    platform5.m_Shape.setPosition(2000, 690);
    m_Platforms.push_back(platform5);

    Platform platform6(sf::Vector2f(150.f, 50.f), sf::Color::Green);
    platform6.m_Shape.setPosition(1750, 850);
    m_Platforms.push_back(platform6);

    Platform platform7(sf::Vector2f(300.f, 50.f), sf::Color::Green);
    platform7.m_Shape.setPosition(3500, 725);
    m_Platforms.push_back(platform7);

    Platform platform8(sf::Vector2f(200.f, 50.f), sf::Color::Green);
    platform8.m_Shape.setPosition(3300, 900);
    m_Platforms.push_back(platform8);

    Platform platform9(sf::Vector2f(10000.f, 500.f), sf::Color::Blue);
    platform9.m_Shape.setPosition(400, 1100);
    m_Platforms.push_back(platform9);


    Platform bridge1(sf::Vector2f(200.f, 50.f), sf::Color::White, true);
    bridge1.m_Shape.setPosition(4400, 490);
    m_Destructible_Platforms.push_back(bridge1);

    Platform bridge2(sf::Vector2f(200.f, 50.f), sf::Color::White, true);
    bridge2.m_Shape.setPosition(4600, 490);
    m_Destructible_Platforms.push_back(bridge2);

    Platform bridge3(sf::Vector2f(200.f, 50.f), sf::Color::White, true);
    bridge3.m_Shape.setPosition(4800, 490);
    m_Destructible_Platforms.push_back(bridge3);

    Platform platform10(sf::Vector2f(800.f, 50.f), sf::Color::Green);
    platform10.m_Shape.setPosition(5000, 490);
    m_Platforms.push_back(platform10);

    Platform bridge4(sf::Vector2f(200.f, 50.f), sf::Color::White, true);
    bridge4.m_Shape.setPosition(5800, 490);
    m_Destructible_Platforms.push_back(bridge4);

    Platform bridge5(sf::Vector2f(200.f, 50.f), sf::Color::White, true);
    bridge5.m_Shape.setPosition(6000, 490);
    m_Destructible_Platforms.push_back(bridge5);

    Platform bridge6(sf::Vector2f(200.f, 50.f), sf::Color::White, true);
    bridge6.m_Shape.setPosition(6200, 490);
    m_Destructible_Platforms.push_back(bridge6);

    Platform platform11(sf::Vector2f(1200.f, 50.f), sf::Color::Green);
    platform11.m_Shape.setPosition(6400, 490);
    m_Platforms.push_back(platform11);

    Platform platform12(sf::Vector2f(2200.f, 50.f), sf::Color::Green);
    platform12.m_Shape.setPosition(7400, 290);
    m_Platforms.push_back(platform12);

    Platform platform13(sf::Vector2f(400.f, 50.f), sf::Color::Green);
    platform13.m_Shape.setPosition(7400, 900);
    m_Platforms.push_back(platform13);

    Platform platform14(sf::Vector2f(300.f, 50.f), sf::Color::Green);
    platform14.m_Shape.setPosition(7700, 650);
    m_Platforms.push_back(platform14);

    Platform platform15(sf::Vector2f(1200.f, 50.f), sf::Color::Green);
    platform15.m_Shape.setPosition(8200, 650);
    m_Platforms.push_back(platform15);

    Platform platform16(sf::Vector2f(1200.f, 50.f), sf::Color::Green);
    platform16.m_Shape.setPosition(9500, 550);
    m_Platforms.push_back(platform16);

    Platform endFlag(sf::Vector2f(50.f, 1000.f), sf::Color::Red);
    endFlag.m_Shape.setPosition(2450, 0);
    endFlag.m_Is_End = true;
    m_Platforms.push_back(endFlag);

    Enemy* new_Enemy = new Enemy;
    new_Enemy->m_Sprite = new_Enemy->m_Standing_Sprite;
    new_Enemy->m_Sprite.setPosition(1200, 490);
    m_Enemies.push_back(new_Enemy);
    Enemy* new_Enemy2 = new Enemy;
    new_Enemy2->m_Sprite = new_Enemy2->m_Standing_Sprite;
    new_Enemy2->m_Sprite.setPosition(3400, 900);
    new_Enemy2->m_Can_Jump = false;
    m_Enemies.push_back(new_Enemy2);
    Enemy* new_Enemy3 = new Enemy;
    new_Enemy3->m_Sprite = new_Enemy3->m_Standing_Sprite;
    new_Enemy3->m_Sprite.setPosition(1500, 1000);
    new_Enemy3->m_Can_Jump = false;
    m_Enemies.push_back(new_Enemy3);

    Enemy* new_Enemy4 = new Enemy;
    new_Enemy4->m_Sprite = new_Enemy4->m_Prone_Sprite;
    new_Enemy4->m_Is_Prone = true;
    new_Enemy4->m_Sprite.setPosition(5400, 490);
    m_Enemies.push_back(new_Enemy4);

    Enemy* new_Enemy5 = new Enemy;
    new_Enemy5->m_Sprite = new_Enemy->m_Standing_Sprite;
    new_Enemy5->m_Sprite.setPosition(6800, 490);
    m_Enemies.push_back(new_Enemy5);

    Enemy* new_Enemy6 = new Enemy;
    new_Enemy6->m_Sprite = new_Enemy6->m_Standing_Sprite;
    new_Enemy6->m_Sprite.setPosition(7600, 900);
    new_Enemy6->m_Can_Jump = false;
    m_Enemies.push_back(new_Enemy6);

    Enemy* new_Enemy7 = new Enemy;
    new_Enemy7->m_Sprite = new_Enemy7->m_Standing_Sprite;
    new_Enemy7->m_Sprite.setPosition(7700, 290);
    m_Enemies.push_back(new_Enemy7);


}
void Level2::Colision(Player& player1, int& ground_Height, sf::Clock fall_Timer)
{
    for (int i = 0; i < m_Platforms.size(); i++)
    {

        if (player1.m_Sprite.getGlobalBounds().intersects(m_Platforms[i].m_Shape.getGlobalBounds()) && player1.m_Is_Jumping == false && player1.m_Is_Falling == false && m_Platforms[i].m_Is_End == false)
        {
            player1.m_Sprite.setPosition(player1.m_Sprite.getPosition().x, m_Platforms[i].m_Shape.getPosition().y - 78);
            player1.m_velocityY = 10;
            ground_Height = m_Platforms[i].m_Shape.getPosition().y - 78;

            //cout << player1.m_Sprite.getPosition().y << endl;
            //cout << ground_Height << endl;
        }
        else if (player1.m_Is_Falling == true)
        {
            if (fall_Timer.getElapsedTime().asSeconds() > .2)
            {

                player1.m_Is_Falling = false;
            }
        }

    }

    for (int i = 0; i < m_Destructible_Platforms.size(); i++)
    {

        if (m_Destructible_Platforms[i].m_Stepped_On == false)
        {
            m_Destructible_Platforms[i].m_Fall_Timer.restart();

        }
        if (player1.m_Sprite.getGlobalBounds().intersects(m_Destructible_Platforms[i].m_Shape.getGlobalBounds()) && player1.m_Is_Jumping == false && player1.m_Is_Falling == false)
        {
            m_Destructible_Platforms[i].m_Stepped_On = true;
            m_Destructible_Platforms[i].m_Shape.setFillColor(sf::Color::Red);
            player1.m_Sprite.setPosition(player1.m_Sprite.getPosition().x, m_Destructible_Platforms[i].m_Shape.getPosition().y - 78);
            player1.m_velocityY = 10;
            ground_Height = m_Destructible_Platforms[i].m_Shape.getPosition().y - 78;
        }
        else if (player1.m_Is_Falling == true)
        {
            if (fall_Timer.getElapsedTime().asSeconds() > .2)
            {
                player1.m_Is_Falling = false;
            }
        }

    }
}
void Level2::Enemy_AI(int enemy_Ground_Height, int ground_Height, bool is_Jumping, bool is_Prone, sf::RenderWindow& window, vector<Bullet*>& enemies_bullet_Position, vector<Bullet*>& bullet_Position, Player& player1, int i, bool is_Swimming)
{

    for (int j = 0; j < m_Platforms.size(); j++)
    {
        if (m_Enemies[i]->m_Sprite.getGlobalBounds().intersects(m_Platforms[j].m_Shape.getGlobalBounds()) && m_Enemies[i]->m_Is_Prone == false)
        {
            m_Enemies[i]->m_Sprite.setPosition(m_Enemies[i]->m_Sprite.getPosition().x, m_Platforms[j].m_Shape.getPosition().y - 78);
            enemy_Ground_Height = m_Platforms[j].m_Shape.getPosition().y - 78;
        }
        else if (m_Enemies[i]->m_Sprite.getGlobalBounds().intersects(m_Platforms[j].m_Shape.getGlobalBounds()) && m_Enemies[i]->m_Is_Prone == true)
        {
            m_Enemies[i]->m_velocityY = 0;
            m_Enemies[i]->m_Sprite.setPosition(m_Enemies[i]->m_Sprite.getPosition().x, m_Platforms[j].m_Shape.getPosition().y - 40);
        }

    }
    if (m_Enemies[i]->m_Sprite.getPosition().y == enemy_Ground_Height)
    {

        if (rand() % 4 == 0 && m_Enemies[i]->m_Is_Prone == false && m_Enemies[i]->m_Can_Jump == true)
        {
            if (m_Enemies[i]->m_Jump_CD.getElapsedTime().asSeconds() > 4)
            {
                m_Enemies[i]->m_velocityY = -20;
                m_Enemies[i]->m_Jump_CD.restart();
            }
        }
    }
    if (rand() % 4 == 1)
    {
        if (m_Enemies[i]->m_Shoot_CD.getElapsedTime().asSeconds() > 1.5 && m_Enemies[i]->m_Sprite.getPosition().x < player1.m_Sprite.getPosition().x + 650 && m_Enemies[i]->m_Sprite.getPosition().x > player1.m_Sprite.getPosition().x - 650)
        {
            m_Enemies[i]->Enemy_Shoot(enemies_bullet_Position, is_Prone, is_Jumping, player1, is_Swimming);
        }
    }
    if (rand() % 4 == 2)
    {

        // new_Enemy->m_velocityY = -20;
         //new_Enemy->m_Direction = random_Vector - new_Enemy->m_Sprite.getPosition();
    }
    if (rand() % 4 == 3)
    {


        //new_Enemy->m_Direction = random_Vector - new_Enemy->m_Sprite.getPosition();
    }


    m_Enemies[i]->Move_Enemy(ground_Height);

    window.draw(m_Enemies[i]->m_Sprite);
    if (m_Enemies[i]->m_Sprite.getPosition().x < player1.m_Sprite.getPosition().x && m_Enemies[i]->m_Sprite.getScale().x > 0)
    {
        if (m_Enemies[i]->m_Is_Prone == false)
        {
            m_Enemies[i]->m_Sprite.setScale(m_Enemies[i]->m_Sprite.getScale().x * -1, m_Enemies[i]->m_Sprite.getScale().y);
        }


    }
    else if (m_Enemies[i]->m_Sprite.getPosition().x < player1.m_Sprite.getPosition().x && m_Enemies[i]->m_Is_Prone == true && m_Enemies[i]->m_Sprite.getScale().x < 0)
    {
        m_Enemies[i]->m_Sprite.setScale(2, m_Enemies[i]->m_Sprite.getScale().y);
    }
    else if (m_Enemies[i]->m_Sprite.getPosition().x > player1.m_Sprite.getPosition().x && m_Enemies[i]->m_Is_Prone == true)
    {
        m_Enemies[i]->m_Sprite.setScale(-2, m_Enemies[i]->m_Sprite.getScale().y);
    }
    else if (m_Enemies[i]->m_Sprite.getPosition().x > player1.m_Sprite.getPosition().x && m_Enemies[i]->m_Sprite.getScale().x < 0)
    {
        if (m_Enemies[i]->m_Is_Prone == false)
        {
            m_Enemies[i]->m_Sprite.setScale(m_Enemies[i]->m_Sprite.getScale().x * -1, m_Enemies[i]->m_Sprite.getScale().y);
        }
    }
    for (int j = bullet_Position.size() - 1; j >= 0; j--)
    {
        if (bullet_Position[j]->m_Sprite.getGlobalBounds().intersects(m_Enemies[i]->m_Sprite.getGlobalBounds()) && m_Enemies[i]->m_Sprite.getGlobalBounds().intersects(bullet_Position[j]->m_Sprite.getGlobalBounds()))
        {
            delete bullet_Position[j];
            bullet_Position.erase(bullet_Position.begin() + j);
            m_Enemies[i]->m_Is_Dead = true;
        }

    }

}