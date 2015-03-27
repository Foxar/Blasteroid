#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class player
{
    public:
        player(int hp, int xPos, int yPos, sf::Texture texture, int rect);
        void shoot(sf::Texture texture, int angle);
        sf::Texture tex;
        sf::Sprite sprite;
        sf::Sprite muzzleSprite;
        sf::Vector2f vel;
        float speed;
        float accel;
        int health;
        int muzzleFrame;
        bool isAccelerating;
};

#endif // PLAYER_H
