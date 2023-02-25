#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Level1.h"
#include "MainMenu.h"
#include "Background.h"


using namespace std;


int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    window.setFramerateLimit(60);
    Player player1;
    MainMenu mainMenu;
    bool levelOne = false;
    bool levelTwo = false;
    //sf::Texture animationTexture;
    //animationTexture.loadFromFile("animationsprites.png");
    //Animation animation(&animationTexture, sf::Vector2u(2, 1), .3f);
    sf::Clock running_Timer;
    sf::Clock shoot_CD;
    float deltaTime = 0.0f;
    sf::Clock deltaClock;
    //player1.m_Sprite = player1.m_Standing_Sprite;
    player1.m_Sprite.setPosition(400, 450);
    //vector<Enemy*> enemies;
    float speed = 4;

    Level1 lvl1;
    Level2 lvl2;
    int ground_Height = 450;
    int enemy_Ground_Height = 412;
    int water_Level = 1000;

    Bullet player_Proj;
    sf::Clock game_Clock;
    sf::Clock fall_Timer;
    sf::Clock run_Animation_Clock;
    float spawn_Rate = 2.f;
    vector<Bullet*> bullet_Position;
    vector<Bullet*> enemies_bullet_Position;
    bool game_Over = false;
    int player_Health = 5;
    //bool is_Falling = false;

    sf::Font font;
    font.loadFromFile("times.ttf");
    sf::Text game_Over_Text;
    game_Over_Text.setFont(font);
    game_Over_Text.setString("GAME OVER");
    game_Over_Text.setFillColor(sf::Color::Red);
    game_Over_Text.setCharacterSize(120);
    
    sf::Text health_Text;
    health_Text.setFont(font);
    health_Text.setFillColor(sf::Color::White);
    health_Text.setCharacterSize(30);


    



    sf::View camera = window.getView();

    while (window.isOpen())
    {
        if (levelOne == false && levelTwo == false)
        {
            
            window.setView(window.getDefaultView());
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                 if (mainMenu.m_Start_Button.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                 {
                     levelOne = true;
                     player1.m_Sprite = player1.m_Standing_Sprite;
                     player1.m_Sprite.setPosition(400, 450);
                 }
            }
            window.clear();
            window.draw(mainMenu.m_Background_Sprite);
            //window.draw(mainMenu.m_Start_Button);
            window.display();
        }
        
        if (game_Over == false && levelOne == true)
        {

            sf::Vector2f current_pos = player1.m_Sprite.getPosition();
            sf::Event event;
            player1.m_Standing_Sprite.setPosition(player1.m_Sprite.getPosition());
            player1.m_Sprite = player1.m_Standing_Sprite;
            player1.m_Standing_Hit_Box.setPosition(player1.m_Sprite.getPosition().x +35, player1.m_Sprite.getPosition().y+35);
            player1.m_Prone_Hit_Box.setPosition(player1.m_Sprite.getPosition().x - 45, player1.m_Sprite.getPosition().y+60);
            player1.m_Jumping_Hit_Box.setPosition(player1.m_Sprite.getPosition().x, player1.m_Sprite.getPosition().y-5);
            player1.m_Swimming_Hit_Box.setPosition(player1.m_Sprite.getPosition().x-10, player1.m_Sprite.getPosition().y - 10);
            player1.m_Running_Hit_Box.setPosition(player1.m_Sprite.getPosition().x + 15, player1.m_Sprite.getPosition().y + 45);
            player1.m_velocityX = 0;
            if (run_Animation_Clock.getElapsedTime().asMilliseconds() < 300)
            {
                player1.m_Running_Sprite_1.setPosition(player1.m_Sprite.getPosition().x, ground_Height + 10);
                player1.m_Running_Sprite = player1.m_Running_Sprite_1;
            }
            else if (run_Animation_Clock.getElapsedTime().asMilliseconds() < 600 && run_Animation_Clock.getElapsedTime().asMilliseconds() > 300)
            {
                player1.m_Running_Sprite_2.setPosition(player1.m_Sprite.getPosition().x, ground_Height + 10);
                player1.m_Running_Sprite = player1.m_Running_Sprite_2;

            }
            else if (run_Animation_Clock.getElapsedTime().asMilliseconds() < 900 && run_Animation_Clock.getElapsedTime().asMilliseconds() > 600)
            {
                player1.m_Running_Sprite_3.setPosition(player1.m_Sprite.getPosition().x, ground_Height + 10);
                player1.m_Running_Sprite = player1.m_Running_Sprite_3;

            }
            else if (run_Animation_Clock.getElapsedTime().asMilliseconds() < 1200 && run_Animation_Clock.getElapsedTime().asMilliseconds() > 900)
            {
                player1.m_Running_Sprite_4.setPosition(player1.m_Sprite.getPosition().x, ground_Height + 10);
                player1.m_Running_Sprite = player1.m_Running_Sprite_4;

            }
            else
            {
                run_Animation_Clock.restart();
            }
            

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && player1.m_Sprite.getPosition().y == ground_Height + 10 && player1.m_Is_Prone == false) {
                    player1.m_velocityY = -15;
                    player1.m_Is_Jumping = true;
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && player1.m_Is_Swimming == true) {
                    player1.m_velocityY = -15;
                    player1.m_Is_Jumping = true;
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && player1.m_Is_Prone == true && player1.m_Sprite.getPosition().y <= water_Level)
                {
                    player1.m_velocityY = 10;
                    player1.m_Is_Falling = true;
                    fall_Timer.restart();
                }
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        Bullet* new_Proj = new Bullet;
                        if (player1.m_Is_Swimming == false)
                        {
                            new_Proj->m_Sprite.setPosition(player1.m_Sprite.getPosition().x + 30, player1.m_Sprite.getPosition().y + 30);
                            //new_Proj->Rotate_Bullet(new_Proj, window);
                        }
                        else
                        {
                            new_Proj->m_Sprite.setPosition(player1.m_Sprite.getPosition().x, player1.m_Sprite.getPosition().y);
                        }
                        bullet_Position.push_back(new_Proj);
                        sf::Vector2f mousePositionFloat = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                        new_Proj->m_Direction = mousePositionFloat - new_Proj->m_Sprite.getPosition();
                        new_Proj->m_Magnitude = sqrt((new_Proj->m_Direction.x * new_Proj->m_Direction.x + new_Proj->m_Direction.y * new_Proj->m_Direction.y));
                        new_Proj->m_Direction.x = new_Proj->m_Direction.x / new_Proj->m_Magnitude;
                        new_Proj->m_Direction.y = new_Proj->m_Direction.y / new_Proj->m_Magnitude;
                        shoot_CD.restart();
                    }
                }
                


            }
            camera.setCenter(player1.m_Sprite.getPosition().x + 250, player1.m_Sprite.getPosition().y + 100);
            if (game_Clock.getElapsedTime().asSeconds() >= spawn_Rate)
            {
               /* Enemy* new_Enemy = new Enemy;

                if (rand() % 2 == 0)
                {
                    new_Enemy->m_velocityX = -2;
                    new_Enemy->m_velocityY = -10;
                    new_Enemy->m_Sprite = new_Enemy->m_Standing_Sprite;
                    new_Enemy->m_Sprite.setPosition(player1.m_Sprite.getPosition().x + window.getSize().x + 50, ground_Height);
                }
                else if (rand() % 2 == 1)
                {
                    new_Enemy->m_velocityX = 0;
                    new_Enemy->m_velocityY = -5;
                    new_Enemy->m_Sprite = new_Enemy->m_Prone_Sprite;
                    new_Enemy->m_player1.m_Is_Prone = true;
                    new_Enemy->m_Sprite.setPosition(player1.m_Sprite.getPosition().x + window.getSize().x + 50, ground_Height + 50);
                }

                enemies.push_back(new_Enemy);

                game_Clock.restart();
                */
            }
            player1.m_Is_Running = false;


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player1.m_Is_Prone == false && player1.m_Sprite.getPosition().x > 400)
            {
                player1.m_velocityX = -4;

            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player1.m_Is_Prone == false)
            {
                player1.m_velocityX = 4;
                if (player1.m_Is_Jumping == false)
                {
                    player1.m_Running_Sprite.setPosition(player1.m_Sprite.getPosition());
                    player1.m_Sprite = player1.m_Running_Sprite;
                    player1.m_Is_Running = true;
                }
                else
                {
                    player1.m_Is_Running = false;
                }
            }
            else
            {
                player1.m_Sprite = player1.m_Standing_Sprite;
            }
            player1.m_Is_Prone = false;

            lvl1.Colision(player1, ground_Height, fall_Timer);
            
            player1.Move_Player(ground_Height);

           
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {

                if (player1.m_Sprite.getPosition().y == ground_Height + 10 && player1.m_Is_Swimming == false)
                {
                    player1.m_Prone_Sprite.setPosition(player1.m_Sprite.getPosition().x, ground_Height + 40);
                    player1.m_Sprite = player1.m_Prone_Sprite;
                    //player1.m_Sprite.setPosition(current_pos.x, ground_Height);
                    player1.m_Is_Prone = true;
                }

            }
            if (player1.m_velocityY < 0)
            {
                player1.m_Jumping_Sprite.setPosition(player1.m_Sprite.getPosition());
                player1.m_Sprite = player1.m_Jumping_Sprite;
                player1.m_Is_Jumping = true;
                player1.m_Jumping_Sprite.rotate(5);
            }
            else if (player1.m_Sprite.getPosition().y >= water_Level)
            {
                player1.m_Swimming_Sprite.setPosition(player1.m_Sprite.getPosition().x, player1.m_Sprite.getPosition().y+70);
                player1.m_Sprite = player1.m_Swimming_Sprite;
                player1.m_Is_Swimming = true;
            }
            else
            {
                player1.m_Is_Jumping = false;
            }
            for (int i = 0; i < lvl1.m_Platforms.size(); i++)
            {

                if (player1.m_Sprite.getGlobalBounds().intersects(lvl1.m_Platforms[i].m_Shape.getGlobalBounds()) && lvl1.m_Platforms[i].m_Is_End == true)
                {
                    levelOne = false;
                    levelTwo = true;
                    player1.m_Sprite = player1.m_Standing_Sprite;
                    player1.m_Sprite.setPosition(400, 450);
                    break;
                }
            }
            window.clear();

            //window.draw(background.m_Background_Sprite);

            window.setView(camera);
            
            for (int i = 0; i < lvl1.m_Platforms.size(); i++)
            {

                    window.draw(lvl1.m_Platforms[i].m_Shape);

            }
            for (int i = lvl1.m_Destructible_Platforms.size() - 1; i >= 0; i--)
            {
                if (lvl1.m_Destructible_Platforms[i].m_Fall_Timer.getElapsedTime().asSeconds() > 2 && lvl1.m_Destructible_Platforms[i].m_Stepped_On == true)
                {
                    lvl1.m_Destructible_Platforms.erase(lvl1.m_Destructible_Platforms.begin() + i);
                }
                else
                {
                    window.draw(lvl1.m_Destructible_Platforms[i].m_Shape);
                }
            }
            
            for (int i = bullet_Position.size() - 1; i > 0; i--)
            {
                bullet_Position[i]->Update_Bullets(bullet_Position, window, i, player1);

            }

            for (int i = enemies_bullet_Position.size()-1 ; i > 0; i--)
            {
                enemies_bullet_Position[i]->Update_Bullets(enemies_bullet_Position,window, i, player1);

            }

            for (int i = 0; i < lvl1.m_Enemies.size(); i++)
            {
                //bug is here
                lvl1.Enemy_AI(enemy_Ground_Height, player1.m_Is_Jumping, player1.m_Is_Prone, window, enemies_bullet_Position, bullet_Position, player1, i, player1.m_Is_Swimming);

            }

             for (int i = lvl1.m_Enemies.size()-1; i >= 0; i--)
             {
                 if (lvl1.m_Enemies[i]->m_Is_Dead == true)
                 {
                     lvl1.m_Enemies.erase(lvl1.m_Enemies.begin() + i);
                 }
             }
             

            if (player1.m_Is_Jumping == true)
            {
                player1.m_Current_Hit_Box = player1.m_Jumping_Hit_Box;
            }
            else if (player1.m_Is_Prone == true)
            {
                player1.m_Current_Hit_Box = player1.m_Prone_Hit_Box;
            }
            else if (player1.m_Is_Swimming == true)
            {
                player1.m_Current_Hit_Box = player1.m_Swimming_Hit_Box;
            }
            else if (player1.m_Is_Running == true)
            {
                player1.m_Current_Hit_Box = player1.m_Running_Hit_Box;
            }
            else
            {
                player1.m_Current_Hit_Box = player1.m_Standing_Hit_Box;
            }
            if (player1.m_Sprite.getPosition().y <= water_Level)
            {
                player1.m_Is_Swimming = false;
            }


            for (int j = enemies_bullet_Position.size() - 1; j >= 0; j--)
            {
                if (enemies_bullet_Position[j]->m_Hitbox.getGlobalBounds().intersects(player1.m_Current_Hit_Box.getGlobalBounds()))
                {
                    //enemies_bullet_Position.erase(bullet_Position.begin() + j);
                    enemies_bullet_Position[j]->m_Sprite.setScale(0, 0);
                    enemies_bullet_Position[j]->m_Hitbox.setScale(0, 0);
                    --player_Health;
                    if (player_Health <= 0)
                    {
                        game_Over = true;
                        game_Over_Text.setPosition(player1.m_Sprite.getPosition().x-110, player1.m_Sprite.getPosition().y-300);
                        window.draw(game_Over_Text);
                    }
                }

            }

            health_Text.setString("Health : " + to_string(player_Health));
            health_Text.setPosition(player1.m_Sprite.getPosition().x - 150, player1.m_Sprite.getPosition().y - 300);

            window.draw(health_Text);

            window.draw(player1.m_Sprite);
            //window.draw(player1.m_Current_Hit_Box);
            window.display();
        }
        else if (game_Over == false && levelTwo == true)
        {

            sf::Vector2f current_pos = player1.m_Sprite.getPosition();
            sf::Event event;
            player1.m_Standing_Sprite.setPosition(player1.m_Sprite.getPosition());
            player1.m_Sprite = player1.m_Standing_Sprite;
            player1.m_Standing_Hit_Box.setPosition(player1.m_Sprite.getPosition().x + 35, player1.m_Sprite.getPosition().y + 35);
            player1.m_Prone_Hit_Box.setPosition(player1.m_Sprite.getPosition().x - 45, player1.m_Sprite.getPosition().y + 60);
            player1.m_Jumping_Hit_Box.setPosition(player1.m_Sprite.getPosition().x, player1.m_Sprite.getPosition().y - 5);
            player1.m_Swimming_Hit_Box.setPosition(player1.m_Sprite.getPosition().x - 10, player1.m_Sprite.getPosition().y - 10);
            player1.m_Running_Hit_Box.setPosition(player1.m_Sprite.getPosition().x + 15, player1.m_Sprite.getPosition().y + 45);
            player1.m_velocityX = 0;
            if (run_Animation_Clock.getElapsedTime().asMilliseconds() < 300)
            {
                player1.m_Running_Sprite_1.setPosition(player1.m_Sprite.getPosition().x, ground_Height + 10);
                player1.m_Running_Sprite = player1.m_Running_Sprite_1;
            }
            else if (run_Animation_Clock.getElapsedTime().asMilliseconds() < 600 && run_Animation_Clock.getElapsedTime().asMilliseconds() > 300)
            {
                player1.m_Running_Sprite_2.setPosition(player1.m_Sprite.getPosition().x, ground_Height + 10);
                player1.m_Running_Sprite = player1.m_Running_Sprite_2;

            }
            else if (run_Animation_Clock.getElapsedTime().asMilliseconds() < 900 && run_Animation_Clock.getElapsedTime().asMilliseconds() > 600)
            {
                player1.m_Running_Sprite_3.setPosition(player1.m_Sprite.getPosition().x, ground_Height + 10);
                player1.m_Running_Sprite = player1.m_Running_Sprite_3;

            }
            else if (run_Animation_Clock.getElapsedTime().asMilliseconds() < 1200 && run_Animation_Clock.getElapsedTime().asMilliseconds() > 900)
            {
                player1.m_Running_Sprite_4.setPosition(player1.m_Sprite.getPosition().x, ground_Height + 10);
                player1.m_Running_Sprite = player1.m_Running_Sprite_4;

            }
            else
            {
                run_Animation_Clock.restart();
            }


            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && player1.m_Sprite.getPosition().y == ground_Height + 10 && player1.m_Is_Prone == false) {
                    player1.m_velocityY = -15;
                    player1.m_Is_Jumping = true;
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && player1.m_Is_Swimming == true) {
                    player1.m_velocityY = -15;
                    player1.m_Is_Jumping = true;
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && player1.m_Is_Prone == true && player1.m_Sprite.getPosition().y <= water_Level)
                {
                    player1.m_velocityY = 10;
                    player1.m_Is_Falling = true;
                    fall_Timer.restart();
                }
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && shoot_CD.getElapsedTime().asMilliseconds() > 320)
                    {
                        Bullet* new_Proj = new Bullet;
                        if (player1.m_Is_Swimming == false)
                        {
                            new_Proj->m_Sprite.setPosition(player1.m_Sprite.getPosition().x + 30, player1.m_Sprite.getPosition().y + 30);
                            //new_Proj->Rotate_Bullet(new_Proj, window);
                        }
                        else
                        {
                            new_Proj->m_Sprite.setPosition(player1.m_Sprite.getPosition().x, player1.m_Sprite.getPosition().y);
                        }
                        bullet_Position.push_back(new_Proj);
                        sf::Vector2f mousePositionFloat = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                        new_Proj->m_Direction = mousePositionFloat - new_Proj->m_Sprite.getPosition();
                        new_Proj->m_Magnitude = sqrt((new_Proj->m_Direction.x * new_Proj->m_Direction.x + new_Proj->m_Direction.y * new_Proj->m_Direction.y));
                        new_Proj->m_Direction.x = new_Proj->m_Direction.x / new_Proj->m_Magnitude;
                        new_Proj->m_Direction.y = new_Proj->m_Direction.y / new_Proj->m_Magnitude;
                        shoot_CD.restart();
                    }
                }



            }
            camera.setCenter(player1.m_Sprite.getPosition().x + 250, player1.m_Sprite.getPosition().y + 100);
            if (game_Clock.getElapsedTime().asSeconds() >= spawn_Rate)
            {
                /* Enemy* new_Enemy = new Enemy;

                 if (rand() % 2 == 0)
                 {
                     new_Enemy->m_velocityX = -2;
                     new_Enemy->m_velocityY = -10;
                     new_Enemy->m_Sprite = new_Enemy->m_Standing_Sprite;
                     new_Enemy->m_Sprite.setPosition(player1.m_Sprite.getPosition().x + window.getSize().x + 50, ground_Height);
                 }
                 else if (rand() % 2 == 1)
                 {
                     new_Enemy->m_velocityX = 0;
                     new_Enemy->m_velocityY = -5;
                     new_Enemy->m_Sprite = new_Enemy->m_Prone_Sprite;
                     new_Enemy->m_player1.m_Is_Prone = true;
                     new_Enemy->m_Sprite.setPosition(player1.m_Sprite.getPosition().x + window.getSize().x + 50, ground_Height + 50);
                 }

                 enemies.push_back(new_Enemy);

                 game_Clock.restart();
                 */
            }
            player1.m_Is_Running = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player1.m_Sprite.getPosition().y > ground_Height - 200)
            {

            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player1.m_Is_Prone == false && player1.m_Sprite.getPosition().x > 400)
            {
                player1.m_velocityX = -4;

            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player1.m_Is_Prone == false)
            {
                player1.m_velocityX = 4;
                if (player1.m_Is_Jumping == false)
                {
                    player1.m_Running_Sprite.setPosition(player1.m_Sprite.getPosition());
                    player1.m_Sprite = player1.m_Running_Sprite;
                    player1.m_Is_Running = true;
                }
                else
                {
                    player1.m_Is_Running = false;
                }
            }
            else
            {
                player1.m_Sprite = player1.m_Standing_Sprite;
            }
            player1.m_Is_Prone = false;

            lvl2.Colision(player1, ground_Height, fall_Timer);

            player1.Move_Player(ground_Height);


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {

                if (player1.m_Sprite.getPosition().y == ground_Height + 10 && player1.m_Is_Swimming == false)
                {
                    player1.m_Prone_Sprite.setPosition(player1.m_Sprite.getPosition().x, ground_Height + 40);
                    player1.m_Sprite = player1.m_Prone_Sprite;
                    //player1.m_Sprite.setPosition(current_pos.x, ground_Height);
                    player1.m_Is_Prone = true;
                }

            }
            if (player1.m_velocityY < 0)
            {
                player1.m_Jumping_Sprite.setPosition(player1.m_Sprite.getPosition());
                player1.m_Sprite = player1.m_Jumping_Sprite;
                player1.m_Is_Jumping = true;
                player1.m_Jumping_Sprite.rotate(5);
            }
            else if (player1.m_Sprite.getPosition().y >= water_Level)
            {
                player1.m_Swimming_Sprite.setPosition(player1.m_Sprite.getPosition().x, player1.m_Sprite.getPosition().y + 70);
                player1.m_Sprite = player1.m_Swimming_Sprite;
                player1.m_Is_Swimming = true;
            }
            else
            {
                player1.m_Is_Jumping = false;
            }

            window.clear();

            //window.draw(background.m_Background_Sprite);

            window.setView(camera);
            for (int i = 0; i < lvl2.m_Platforms.size(); i++)
            {

                if (player1.m_Sprite.getGlobalBounds().intersects(lvl2.m_Platforms[i].m_Shape.getGlobalBounds()) && lvl2.m_Platforms[i].m_Is_End == true)
                {
                    levelTwo = false;
                    break;
                }
                else
                {
                    window.draw(lvl2.m_Platforms[i].m_Shape);
                }

            }
            for (int i = lvl2.m_Destructible_Platforms.size() - 1; i >= 0; i--)
            {
                if (lvl2.m_Destructible_Platforms[i].m_Fall_Timer.getElapsedTime().asSeconds() > 2 && lvl2.m_Destructible_Platforms[i].m_Stepped_On == true)
                {
                    lvl2.m_Destructible_Platforms.erase(lvl2.m_Destructible_Platforms.begin() + i);
                }
                else
                {
                    window.draw(lvl2.m_Destructible_Platforms[i].m_Shape);
                }
            }

            for (int i = bullet_Position.size() - 1; i > 0; i--)
            {
                bullet_Position[i]->Update_Bullets(bullet_Position, window, i, player1);

            }

            for (int i = enemies_bullet_Position.size() - 1; i > 0; i--)
            {
                enemies_bullet_Position[i]->Update_Bullets(enemies_bullet_Position, window, i, player1);

            }

            for (int i = 0; i < lvl2.m_Enemies.size(); i++)
            {
                lvl2.Enemy_AI(enemy_Ground_Height, ground_Height, player1.m_Is_Jumping, player1.m_Is_Prone, window, enemies_bullet_Position, bullet_Position, player1, i, player1.m_Is_Swimming);

            }

            for (int i = lvl2.m_Enemies.size() - 1; i >= 0; i--)
            {
                if (lvl2.m_Enemies[i]->m_Is_Dead == true)
                {
                    lvl2.m_Enemies.erase(lvl2.m_Enemies.begin() + i);
                }
            }


            if (player1.m_Is_Jumping == true)
            {
                player1.m_Current_Hit_Box = player1.m_Jumping_Hit_Box;
            }
            else if (player1.m_Is_Prone == true)
            {
                player1.m_Current_Hit_Box = player1.m_Prone_Hit_Box;
            }
            else if (player1.m_Is_Swimming == true)
            {
                player1.m_Current_Hit_Box = player1.m_Swimming_Hit_Box;
            }
            else if (player1.m_Is_Running == true)
            {
                player1.m_Current_Hit_Box = player1.m_Running_Hit_Box;
            }
            else
            {
                player1.m_Current_Hit_Box = player1.m_Standing_Hit_Box;
            }
            if (player1.m_Sprite.getPosition().y <= water_Level)
            {
                player1.m_Is_Swimming = false;
            }


            for (int j = enemies_bullet_Position.size() - 1; j >= 0; j--)
            {
                if (enemies_bullet_Position[j]->m_Hitbox.getGlobalBounds().intersects(player1.m_Current_Hit_Box.getGlobalBounds()))
                {
                    //enemies_bullet_Position.erase(bullet_Position.begin() + j);
                    enemies_bullet_Position[j]->m_Sprite.setScale(0, 0);
                    enemies_bullet_Position[j]->m_Hitbox.setScale(0, 0);
                    --player_Health;
                    if (player_Health <= 0)
                    {
                        game_Over = true;
                        game_Over_Text.setPosition(player1.m_Sprite.getPosition().x - 110, player1.m_Sprite.getPosition().y - 300);
                        window.draw(game_Over_Text);
                    }
                }

            }

            health_Text.setString("Health : " + to_string(player_Health));
            health_Text.setPosition(player1.m_Sprite.getPosition().x - 150, player1.m_Sprite.getPosition().y - 300);

            window.draw(health_Text);

            window.draw(player1.m_Sprite);
            //window.draw(player1.m_Current_Hit_Box);
            window.display();
        }
        else
        {
            sf::Event event;



            while (window.pollEvent(event))
            {
               if (event.type == sf::Event::Closed)
                 window.close();
            }

        }

        
    }
    for (int i = lvl1.m_Platforms.size() - 1; i >= 0; i--)
    {
        lvl1.m_Platforms.erase(lvl1.m_Platforms.begin() + i);
    }
    for (int i = enemies_bullet_Position.size() - 1; i >= 0; i--)
    {
        delete enemies_bullet_Position[i];
    }
    for (int i = bullet_Position.size() - 1; i >= 0; i--)
    {
        delete bullet_Position[i];
    }
    return 0;
}