#include "asteroid.h"
#include "rectController.h"
#include <random>
#include <chrono>

asteroid::asteroid(int Size, int x, int y, sf::Texture texture)
{
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed1);
    std::uniform_int_distribution<int> size1rect(0, 11);
    std::uniform_int_distribution<int> size2rect(12, 17);
    std::uniform_int_distribution<int> size3rect(18, 20);
    std::uniform_int_distribution<int> size0rect(0, 5);

    switch(Size)
    {
    case 1:
        this->rect = size1rect(generator);
        this->Size = 1;
        break;
    case 2:
        this->rect = size2rect(generator);
        this->Size = 2;
        break;
    case 3:
        this->rect = size3rect(generator);
        this->Size = 3;
        break;
    case 0:
        this->rect = size0rect(generator);
        this->Size = 0;
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
    case 0:
        this->rect = rect
        this->Size = 0;
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
