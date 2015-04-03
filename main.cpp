#include <SFML/Graphics.hpp>
#include "global.h"
#include "player.h"
#include "asteroid.h"
#include "rectController.h"
#include "listController.h"
#include <iostream>
#include <windows.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <chrono>

//TO DO
//
//
//
//ADD MENUS
//DIFFERENT SHIPS
//DIFFERENT ATTACKS
//RANDOM ASTEROIDS
//
//
//
//MORE COMMENTS
//
//MAKE CAMERA MOVE WHEN SHIP APPROACHES BORDER OF THE SCREEN



void gamePlay();
void menu();
void setRects();

int getAngle(double mX, double mY);
sf::Vector2f getMovement(double angle);

int gameState = 0;

bool LMB = false;

sf::RenderWindow app;
sf::View camera;


int counter = 0;
int timeSinceStart = 0;
sf::Vector2f screenShake;
float screenShakeCounter = 0;

sf::Vector2f cameraVel;

int main()
{
    //WINDOW CREATION
    sf::RenderWindow app(sf::VideoMode(800, 600, 32), "Blasteroid");
    camera.reset(sf::FloatRect(0, 0, 640, 480));
    app.setVerticalSyncEnabled(true);
    app.setView(camera);
    screenShake.x = 0;
    screenShake.y = 0;
    cameraVel.x = 0;
    cameraVel.y = 0;
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

    sf::Texture partTex;
    partTex.loadFromFile("Assets/particles.png");
    partTex.setSmooth(true);

    //CREATE OBJECTS
    player pObj(100, 250, 250, spreadtex);
    asteroid aster(3, 400, 300, spreadtex);
    aster.speed = 0;

    //SEED FOR RANDOM GENERATION
    unsigned shakeSeed = std::chrono::system_clock::now().time_since_epoch().count();
    //RANDOM VALUE TO MOVE CAMERA BY TO SIMULATE SHAKE GENERATOR
    std::default_random_engine shakeGenerator(shakeSeed);
    std::uniform_int_distribution<int> shakeDist(1, 20);

    astList.push_back(aster);

    while(app.isOpen())
    {
            //UPDATE THE VIEWPORT OF THE WINDOW TO THE CAMERA
            app.setView(camera);
            //RESET CAMERA SPEED


            //RESET POBJ MEMBERS
            pObj.accel = 0;
            pObj.isAccelerating = false;
            pObj.sprite.setTextureRect(shipRects[0]);
            pObj.sprite.setOrigin(pObj.sprite.getTextureRect().width/2, pObj.sprite.getTextureRect().height/2);
            pObj.vel.x = getMovement(pObj.sprite.getRotation()).x;
            pObj.vel.y = getMovement(pObj.sprite.getRotation()).y;
            if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
               pObj.speed > -1 &&
               pObj.speed < 1)
            {
                pObj.speed = 0;
            }

            //MOUSE POSITION GET
            sf::Vector2i mouseWindow = sf::Mouse::getPosition(app);
            //CONVERT MOUSE POSITION SO IT MATCHES CAMERA
            sf::Vector2f mouseCamera = app.mapPixelToCoords(mouseWindow);

            //RESET SEED FOR RANDOM GENERATION
            unsigned shakeSeed = std::chrono::system_clock::now().time_since_epoch().count();
            shakeGenerator = std::default_random_engine(shakeSeed);



            //HOW MANY FRAMES PASSED SINCE START
            counter++;
            timeSinceStart = counter / 60;  //HOW MANY SECONDS PASSED SINCE START OF THE GAME

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
                pObj.sprite.setRotation(getAngle(mouseCamera.x - pObj.sprite.getPosition().x, mouseCamera.y - pObj.sprite.getPosition().y) + 90);
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
                pObj.sprite.setTextureRect(playerShipShootRects[1][pObj.muzzleFrame - 1][pObj.shootingLeft]);
            }
            else
            {
                pObj.sprite.setTextureRect(playerShipShootRects[0][pObj.muzzleFrame - 1][pObj.shootingLeft]);
            }
            pObj.sprite.setOrigin(pObj.sprite.getTextureRect().width/2, pObj.sprite.getTextureRect().height/2);
            pObj.muzzleFrame++;
            if(pObj.muzzleFrame >= 6)
            {
                pObj.muzzleFrame = 0;
            }
        }
        for(int i = 0; i < partList.size(); i++)
        {
            if(partList[i].alive)
            {
                switch(partList[i].activeAnim)
                {
                case 1:
                    partList[i].sprite.setTextureRect(partRect[partList[i].frame][0]);  //animation1
                    partList[i].sprite.setOrigin(partList[i].sprite.getLocalBounds().width/2, partList[i].sprite.getLocalBounds().height/2);
                    break;
                default:
                    break;
                }
                if(partList[i].frame < partList[i].maxFrame)
                {
                    partList[i].frame++;
                }
                else
                {
                    partList[i].alive = false;
                    partList[i].frame = 0;
                }
            }
        }


        //ASTEROID SPAWN PROTECTION
        for(int i = 0; i < astList.size(); i++)
        {
            astList[i].immoTime--;
            if(astList[i].immoTime < 0)
                astList[i].immoTime = 0;
        }

        //COLLISION DETECTION
        for(int i = 0; i < bulletList.size(); i++)
        {
            for(int n = 0; n < astList.size(); n++)
            {
                if(bulletList[i].sprite.getGlobalBounds().intersects(astList[n].sprite.getGlobalBounds()) &&
                   astList[n].immoTime <= 0)
                {
                    int astSize = astList[n].Size;
                    int nPosX = astList[n].sprite.getPosition().x;
                    int nPosY = astList[n].sprite.getPosition().y;


                    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
                    std::default_random_engine generator(seed1);
                    std::uniform_real_distribution<float> velDist(1.0, 20.0);       //RANDOM DIRECTION DISTRIBUTION
                    std::uniform_real_distribution<float> speedDist1(0.05, 0.5);    //RANDOM SPEED FOR SIZE1 DIST.
                    std::uniform_real_distribution<float> speedDist2(0.05, 0.3);    //RANDOM SPEED FOR SIZE2 DIST.
                    std::uniform_int_distribution<int> rotDist(0, 360);             //RANDOM ROTATION DIST.
                    std::uniform_real_distribution<float> rotSpdDist(0.0, 5.0);     //RANDOM ROTATION SPEED DIST.

                    std::uniform_int_distribution<int> rectDist1(0, 12);            //RANDOM SIZE1 RECT DIST.
                    std::uniform_int_distribution<int> rectDist2(13, 18);           //RANDOM SIZE2 RECT DIST.
                    std::uniform_int_distribution<int> rectDist3(19, 20);           //RANDOM SIZE3 RECT DIST.

                    if(astList[n].Size == 3)
                    {

                        bulletList[i].sprite.move(-5000, -5000);

                        asteroid astToAdd1(1, nPosX, nPosY, spreadtex); // FEW TEMPLATE ASTEROIDS
                        asteroid astToAdd2(2, nPosX, nPosY, spreadtex);


                        for(int i = 0; i < 2; i++)
                        {
                            astToAdd2.immoTime = 60;//SPAWN PROTECTION

                            int rectToUse = rectDist2(generator);//RANDOM RECT PICK
                            asteroid astToAdd2(2, nPosX, nPosY, spreadtex, rectToUse);//REDEFINITION WITH NEW RECT

                            //CALCULATING A RANDOM RIECTION
                            float rand1 = velDist(generator);
                            rand1-= 10;
                            float rand2 = velDist(generator);
                            rand2-= 10;
                            astToAdd2.vel.x = rand1;
                            astToAdd2.vel.y = rand2;
                            //CALCULATING RANDOM SPEED
                            astToAdd2.speed = speedDist2(generator);
                            //CALCULATING RANDOM ROTATION
                            astToAdd2.sprite.setRotation(rotDist(generator));
                            //CALCULATING RANDOM ROTATION SPEED
                            astToAdd2.rotSpeed = rotSpdDist(generator) - 2.5;
                            //ADDED TO LIST
                            astList.push_back(astToAdd2);
                        }
                        for(int i = 0; i < 3; i++)                          //CHECK THE LOOP ABOVE FOR REFERENCE
                        {
                            astToAdd1.immoTime = 60;
                            int rectToUse = rectDist1(generator);
                            asteroid astToAdd1(1, nPosX, nPosY, spreadtex, rectToUse);

                            float rand1 = velDist(generator);
                            rand1-= 10;
                            float rand2 = velDist(generator);
                            rand2-= 10;
                            astToAdd1.vel.x = rand1;
                            astToAdd1.vel.y = rand2;

                            astToAdd1.speed = speedDist1(generator);

                            astToAdd1.sprite.setRotation(rotDist(generator));

                            astToAdd1.rotSpeed = rotSpdDist(generator) - 2.5;

                            astList.push_back(astToAdd1);
                        }


                    }

                    if(astList[n].Size == 2)
                    {

                        asteroid astToAdd(1, nPosX, nPosY, spreadtex);

                        for(int i = 0; i < 3; i++)                          //CHECK THE LOOP ABOVE FOR REFERENCE
                        {
                            astToAdd.immoTime = 60;
                            int rectToUse = rectDist1(generator);
                            asteroid astToAdd(1, nPosX, nPosY, spreadtex, rectToUse);

                            float rand1 = velDist(generator);
                            rand1-= 10;
                            float rand2 = velDist(generator);
                            rand2-= 10;
                            astToAdd.vel.x = rand1;
                            astToAdd.vel.y = rand2;

                            astToAdd.speed = speedDist1(generator);

                            astToAdd.sprite.setRotation(rotDist(generator));

                            astToAdd.rotSpeed = rotSpdDist(generator) - 2.5;

                            astList.push_back(astToAdd);
                        }
                    }

                    astList.erase(astList.begin() + n);

                    particles particleToAdd(nPosX, nPosY, 0, 0, 0, partTex);
                    particleToAdd.setAnim("astExplode");

                    screenShakeCounter = 1;

                    partList.push_back(particleToAdd);

                }
            }
        }

        int playerDistanceCamera[4];
        playerDistanceCamera[0] = camera.getCenter().y - (camera.getSize().y / 2) - pObj.sprite.getPosition().y;
        playerDistanceCamera[1] = camera.getCenter().x + (camera.getSize().x / 2) - pObj.sprite.getPosition().x;
        playerDistanceCamera[2] = camera.getCenter().y  + (camera.getSize().y / 2) - pObj.sprite.getPosition().y;
        playerDistanceCamera[3] = camera.getCenter().x - pObj.sprite.getPosition().x;

            if(playerDistanceCamera[0] >= -250)
            {
                cameraVel.y = -(pObj.vel.y * pObj.speed);
            }
            else if(playerDistanceCamera[2] <= 250)
            {
                cameraVel.y = -(pObj.vel.y * pObj.speed);
            }
            else if(!playerDistanceCamera[0] >= -250 &&
                    !playerDistanceCamera[2] <= 250)
            {
                cameraVel.y = 0;
            }
            if(playerDistanceCamera[3] >= -250)
            {
                cameraVel.x = pObj.vel.x * pObj.speed;
            }

            if(playerDistanceCamera[1] <= 250)
            {
                cameraVel.x = pObj.vel.x * pObj.speed;
            }
            else if(!playerDistnaceCamera[3] >= -250 &&
                    !playerDistanceCaemra[1] <= 250)
            {
                cameraVel.x = 0;
            }


        //SLOWDOWN
        if((mouseCamera.x - pObj.sprite.getPosition().x <= 50 && mouseCamera.x - pObj.sprite.getPosition().x >= - 50) &&
           (mouseCamera.y - pObj.sprite.getPosition().y <= 50 && mouseCamera.y - pObj.sprite.getPosition().y >= - 50) &&
           pObj.speed > 0)
        {
            if(pObj.speed == 0.1)
            {
                pObj.accel = 0.2;
            }
            pObj.accel = -0.2;
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
        for(int i = 0; i < astList.size(); i++)
        {
            astList[i].sprite.move(astList[i].speed * astList[i].vel.x, astList[i].speed * astList[i].vel.y);
            astList[i].sprite.rotate(astList[i].rotSpeed);
        }
        //DISPLAY
        for(int i = 0; i < bulletList.size(); i++)
        {
            bulletList[i].sprite.setTexture(spreadtex);
            app.draw(bulletList[i].sprite);
        }
        app.draw(pObj.sprite);
        for(int i = 0; i < astList.size(); i++)
        {
            astList[i].sprite.setTexture(spreadtex);
            app.draw(astList[i].sprite);
        }
        for(int i = 0; i < partList.size(); i++)
        {
            partList[i].sprite.setTexture(partTex);
            app.draw(partList[i].sprite);
        }
        if(screenShakeCounter > 0)
        {
            screenShake.x = (shakeDist(shakeGenerator) - 10) / screenShakeCounter;
            screenShake.y = screenShake.x;


            screenShakeCounter+= 0.5;

            if(screenShakeCounter > 9)
            {
                screenShake.x = 0;
                screenShake.y = 0;
                screenShakeCounter = 0;
            }
        }
        camera.move(screenShake.x + cameraVel.x, screenShake.y + cameraVel.y);
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

