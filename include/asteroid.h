#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>

class asteroid
{
    public:
        asteroid(int Size, int xPos, int yPos, sf::Texture texture);
        asteroid();
        int Size;
        sf::Sprite sprite;
        sf::Texture tex;
        int rect;
        sf::Vector2f vel;
        int speed;
        bool dead;
        int immoTime;
};

#endif // ASTEROID_H
