#include <SFML/Graphics.hpp>
#include "global.h"
#include "player.h"
#include "asteroid.h"
#include "rectController.h"
#include "listController.h"
#include <iostream>
#include <windows.h>
#include <cmath>

//TO DO
//
//
//
//ADD MENUS
//DIFFERENT SHIPS
//DIFFERENT ATTACKS
//RANDOM ASTEROIDS
//ASTEROIDS EXPLOSIONS
//
//
//IMPORTANT!!! DIFFERENT SHIP RECTS USE



void gamePlay();
void menu();
void setRects();

int getAngle(double mX, double mY);
sf::Vector2f getMovement(double angle);

int gameState = 0;

bool LMB = false;

sf::RenderWindow app;

int main()
{
    //WINDOW CREATION
    sf::RenderWindow app(sf::VideoMode(800, 600, 32), "Blasteroid");
    app.setVerticalSyncEnabled(true);
    //FRAMERATE CAP
    app.setFramerateLimit(60);
    //RAND SEED
    srand(GetTickCount());

    //RECTANGLES SETTING
    setRects();

    //TEXTURE LOADING
    sf::Texture spreadtex;
    spreadtex.loadFromFile("Assets/spreadsheet.png");
    spreadtex.setSmooth(true);

    //CREATE OBJECTS
    player pObj(100, 50, 50, spreadtex);
    asteroid ast1(3, 100, 100, spreadtex);


    while(app.isOpen())
    {

            //RESET POBJ MEMBERS
            pObj.accel = 0;
            pObj.isAccelerating = false;
            pObj.sprite.setTextureRect(shipRects[0]);
            pObj.sprite.setOrigin(pObj.sprite.getTextureRect().width/2, pObj.sprite.getTextureRect().height/2);
            pObj.vel.x = getMovement(pObj.sprite.getRotation()).x;
            pObj.vel.y = getMovement(pObj.sprite.getRotation()).y;

            if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && pObj.speed >= 0)
            {
                pObj.accel = -0.2;
                pObj.sprite.setTextureRect(shipRects[0]);
                if(pObj.speed == 0)
                {
                    pObj.accel = 0;
                }
            }
            //ACCELERATING
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                if(pObj.speed < 5)
                {
                    pObj.accel = 0.2;
                }
                pObj.sprite.setTextureRect(shipRects[1]);
                pObj.isAccelerating = true;
            }
            if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                LMB = false;

            }

        //CALCULATING DIRECTION OF MOVING


        sf::Event event;
        while(app.pollEvent(event))
        {
            //CLOSE WINDOW
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                app.close();
            }
            //ROTATING
            if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                pObj.sprite.setRotation(getAngle(sf::Mouse::getPosition(app).x - pObj.sprite.getPosition().x, sf::Mouse::getPosition(app).y - pObj.sprite.getPosition().y) + 90);
            }
            //SHOOTING
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !LMB)
            {
                pObj.muzzleFrame = 1;
                pObj.shoot(spreadtex, pObj.sprite.getRotation());
                //std::cout << "B" << 1 <<" movement :" << bulletList[0].xVel <<  std::endl;
                LMB = true;

            }
        }

        //ANIMATIONS
        if(pObj.muzzleFrame > 0 && pObj.muzzleFrame < 6)
        {
            if(pObj.isAccelerating)
            {
                pObj.sprite.setTextureRect(playerShipShootRects[1][pObj.muzzleFrame - 1]);
            }
            else
            {
                pObj.sprite.setTextureRect(playerShipShootRects[0][pObj.muzzleFrame - 1]);
            }
            pObj.sprite.setOrigin(pObj.sprite.getTextureRect().width/2, pObj.sprite.getTextureRect().height/2);
            pObj.muzzleFrame++;
            if(pObj.muzzleFrame >= 6)
            {
                pObj.muzzleFrame = 0;
            }
        }


        //SLOWDOWN
        if((sf::Mouse::getPosition(app).x - pObj.sprite.getPosition().x <= 50 && sf::Mouse::getPosition(app).x - pObj.sprite.getPosition().x >= - 50) &&
           (sf::Mouse::getPosition(app).y - pObj.sprite.getPosition().y <= 50 && sf::Mouse::getPosition(app).y - pObj.sprite.getPosition().y >= - 50) &&
           pObj.speed > 0)
        {
            if(pObj.speed == 0.1)
            {
                pObj.accel = 0.2;
            }
            pObj.accel = -0.2;
        }
        if(pObj.sprite.getGlobalBounds().left > 800 && pObj.vel.x > 0)
        {
            pObj.sprite.setPosition(-pObj.sprite.getLocalBounds().width, pObj.sprite.getPosition().y);
        }
        else if(pObj.sprite.getGlobalBounds().top > 600 && pObj.vel.y < 0)
        {
            pObj.sprite.setPosition(pObj.sprite.getPosition().x, -pObj.sprite.getLocalBounds().height);
        }

        else if(pObj.sprite.getGlobalBounds().top + pObj.sprite.getLocalBounds().height < 0 && pObj.vel.y > 0)
        {
            pObj.sprite.setPosition(pObj.sprite.getPosition().x, 600 + pObj.sprite.getLocalBounds().height);
        }
        else if(pObj.sprite.getGlobalBounds().left + pObj.sprite.getLocalBounds().width < 0 && pObj.vel.x < 0)
        {
            pObj.sprite.setPosition(800 + pObj.sprite.getLocalBounds().width,  pObj.sprite.getPosition().y);
        }

        //GARBAGE COLLECTION
        for(int i = 0; i < bulletList.size(); i++)
        {
            if(bulletList[i].sprite.getPosition().x > 800 ||
               bulletList[i].sprite.getPosition().x < 0 ||
               bulletList[i].sprite.getPosition().y > 600 ||
               bulletList[i].sprite.getPosition().y < 0)
            {
                bulletList.erase(bulletList.begin() + i);
            }
        }

        //KEEP BULLETS TURNED CORRECT WAY
        for(int i = 0; i < bulletList.size(); i++)
        {
            bulletList[i].sprite.setRotation(getAngle(bulletList[i].vel.x, bulletList[i].vel.y) - 90);
        }

        //SPEED
        pObj.speed += pObj.accel;
        //MOVEMENT
        pObj.sprite.move(pObj.vel.x * pObj.speed, pObj.vel.y * -pObj.speed);
        for(int i = 0; i < bulletList.size(); i++)
        {
            bulletList[i].sprite.move(bulletList[i].vel.x * bulletList[i].speed, bulletList[i].vel.y * bulletList[i].speed);
        }
        //DISPLAY
        for(int i = 0; i < bulletList.size(); i++)
        {
            bulletList[i].sprite.setTexture(spreadtex);
            app.draw(bulletList[i].sprite);
        }
        app.draw(pObj.sprite);
        app.draw(ast1.sprite);

        app.display();
        app.clear(sf::Color::Black);

    }
    return 0;
}

void menu()
{


    return;
}

void gamePlay()
{

    return;
}

int getAngle(double mX, double mY)
{
    int angle = atan2(mY, mX) * 180 / 3.1415926536;

    return angle;
}

sf::Vector2f getMovement(double angle)
{
    double yMov = cos(angle * (3.1415926536 / 180));
    double xMov = sin(angle * (3.1415926536 / 180));
return sf::Vector2f(xMov, yMov);
}

