#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class bullet
{
    public:
        bullet(int xPos, int yPos, float xVelocity, float yVelocity, sf::Texture texture, int speed, int rot);
        sf::Sprite sprite;
        sf::Texture tex;
        sf::Vector2f vel;
        int speed;
};

#endif // BULLET_H
