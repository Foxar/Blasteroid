#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>

class asteroid
{
    public:
        asteroid(int Size, int xPos, int yPos, sf::Texture texture);
        sf::Sprite sprite;
        sf::Texture tex;
        int rect;
};

#endif // ASTEROID_H
