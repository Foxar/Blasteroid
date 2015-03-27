#include "asteroid.h"
#include "rectController.h"


asteroid::asteroid(int Size, int x, int y, sf::Texture texture)
{
    switch(Size)
    {
    case 1:
        this->rect = rand() % 12;
        break;
    case 2:
        this->rect = rand() % 6 + 12;
        break;
    case 3:
        this->rect = rand() % 3 + 18;
        break;
    default:
        break;
    }

    this->tex = texture;
    this->sprite.setTexture(this->tex);
    this->sprite.setTextureRect(astRects[this->rect]);
    this->sprite.setPosition(x, y);

}
