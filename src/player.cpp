#include "player.h"
#include "rectController.h"
#include "bullet.h"
#include "listController.h"
#include <iostream>

player::player()
{

}

player::player(int hp, int x, int y, sf::Texture texture)
{
    this->health = hp;
    this->sprite.setPosition(x, y);
    this->tex = texture;
    this->sprite.setTexture(this->tex);

    this->sprite.setTextureRect(shipRects[0]);

    this->sprite.setOrigin(this->sprite.getLocalBounds().width/2,
                           this->sprite.getLocalBounds().height/2);
    this->accel = 0;
    this->speed = 0;
    this->isAccelerating = false;
    this->shootingLeft = false;
    this->invuTime = 60;
    this->points = 0;
}

void player::shoot(sf::Texture texture, int angle)
{



    if(this->shootingLeft)
    {
        float dx, dy;

        float a1, a2, b1, b2;


        bullet newBullet(this->sprite.getPosition().x + this->vel.x * 15,
                        this->sprite.getPosition().y + -this->vel.y * 15,
                        this->vel.x,
                        this->vel.y,
                        texture,
                        10 + this->speed,
                        angle);

        sf::Vector2f A(this->sprite.getPosition().x, this->sprite.getPosition().y);
        sf::Vector2f B(this->sprite.getPosition().x + this->vel.x, this->sprite.getPosition().y + (-this->vel.y));

        dx = B.x - A.x;
        dy = B.y - A.y;

        a1 = B.x - dy / 2;
        b1 = B.y + dx / 2;
        a2 = B.x + dy / 2;
        b2 = B.y - dx / 2;

        newBullet.sprite.move((a2 - a1) * 11, (b2 - b1) * 11);

        bulletList.push_back(newBullet);
    }


    else if(this->shootingLeft == false)
    {

        float dx, dy;

        float a1, a2, b1, b2;


        bullet newBullet2(this->sprite.getPosition().x + this->vel.x * 15,
                     this->sprite.getPosition().y + -this->vel.y * 15,
                     this->vel.x,
                     this->vel.y,
                     texture,
                     10 + this->speed,
                     angle);

        sf::Vector2f A(this->sprite.getPosition().x, this->sprite.getPosition().y);
        sf::Vector2f B(this->sprite.getPosition().x + this->vel.x, this->sprite.getPosition().y + (-this->vel.y));

        dx = B.x - A.x;
        dy = B.y - A.y;

        a1 = B.x - dy / 2;
        b1 = B.y + dx / 2;
        a2 = B.x + dy / 2;
        b2 = B.y - dx / 2;

        newBullet2.sprite.move(-(a2 - a1) * 11, -(b2 - b1) * 11);


        bulletList.push_back(newBullet2);
    }

    this->shootingLeft = !this->shootingLeft;


}
