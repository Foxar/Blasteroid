#include "bullet.h"
#include "rectController.h"
#include <iostream>

bullet::bullet(int xPos, int yPos, float xVelocity, float yVelocity, sf::Texture texture, int speed, int rot)
{
    this->tex = texture;
    this->sprite.setTexture(this->tex);
    this->sprite.setTextureRect(plasma[0]);
    this->sprite.setOrigin(this->sprite.getLocalBounds().width/2, this->sprite.getLocalBounds().top);
    this->sprite.setPosition(xPos, yPos);
    this->sprite.setRotation(rot);
    this->vel.x = xVelocity;
    this->vel.y = -yVelocity;
    this->speed = speed;
    std::cout<< this->vel.x << " AND " << this->vel.y << std::endl;
}
