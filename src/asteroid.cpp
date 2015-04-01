#include "asteroid.h"
#include "rectController.h"
#include <random>

asteroid::asteroid(int Size, int x, int y, sf::Texture texture)
{

    switch(Size)
    {
    case 1:
        this->rect = rand() % 12;
        this->Size = 1;
        break;
    case 2:
        this->rect = rand() % 6 + 12;
        this->Size = 2;
        break;
    case 3:
        this->rect = rand() % 3 + 18;
        this->Size = 3;
        break;
    default:
        break;
    }

    this->tex = texture;
    this->sprite.setTexture(this->tex);
    this->sprite.setTextureRect(astRects[this->rect]);
    this->sprite.setPosition(x, y);
    this->immoTime = 60;
    this->rotSpeed = 0;
    this->sprite.setOrigin(this->sprite.getLocalBounds().width/2, this->sprite.getLocalBounds().height/2);
}

asteroid::asteroid(int Size, int x, int y, sf::Texture texture, int rect)
{
    switch(Size)
    {
    case 1:
        this->rect = rect;
        this->Size = 1;
        break;
    case 2:
        this->rect = rect;
        this->Size = 2;
        break;
    case 3:
        this->rect = rect;
        this->Size = 3;
        break;
    default:
        break;
    }

    this->tex = texture;
    this->sprite.setTexture(this->tex);
    this->sprite.setTextureRect(astRects[this->rect]);
    this->sprite.setPosition(x, y);
    this->immoTime = 60;
    this->rotSpeed = 0;
    this->sprite.setOrigin(this->sprite.getLocalBounds().width/2, this->sprite.getLocalBounds().height/2);
}
