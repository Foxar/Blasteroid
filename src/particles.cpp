#include "particles.h"

particles::particles(int x, int y, int velX, int velY, int speed, sf::Texture tex)
{
    this->rect = rect;
    this->sprite.setPosition(x, y);
    this->sprite.setTexture(tex);
    this->sprite.setTextureRect(rect);
    this->vel.x = velX;
    this->vel.y = velY;
    this->speed = speed;
    this->sprite.setOrigin(this->sprite.getLocalBounds().width/2, this->sprite.getLocalBounds().height/2);
    this->frame = 0;
    this->alive = true;
    this->activeAnim = 0;

}

void particles::setAnim(std::string strArgument)
{
    std::string str1 ("astExplode");

    if(str1.compare(strArgument) == 0)
    {
        this->activeAnim = 1;
        this->maxFrame = 6;
    }
}
