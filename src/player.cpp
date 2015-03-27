#include "player.h"
#include "rectController.h"
#include "bullet.h"
#include "listController.h"
#include <iostream>


player::player(int hp, int x, int y, sf::Texture texture, int rect)
{
    this->health = hp;
    this->sprite.setPosition(x, y);
    this->tex = texture;
    this->sprite.setTexture(this->tex);
    this->sprite.setTextureRect(shipRects[rect]);
    this->sprite.setOrigin(this->sprite.getLocalBounds().width/2,
                           this->sprite.getLocalBounds().height/2);
    this->accel = 0;
    this->speed = 0;
    this->isAccelerating = false;
}

void player::shoot(sf::Texture texture, int angle)
{


std::cout << "SHIT:" << this->vel.x << std::endl;
    bullet newBullet(this->sprite.getPosition().x + this->vel.x * 20,
                     this->sprite.getPosition().y + -this->vel.y * 20,
                     this->vel.x,
                     this->vel.y,
                     texture,
                     10 + this->speed,
                     angle);

    bulletList.push_back(newBullet);
}
