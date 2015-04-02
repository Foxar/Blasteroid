#ifndef PARTICLES_H
#define PARTICLES_H

#include <SFML/Graphics.hpp>


class particles
{
    public:
        particles(int x, int y, int velX, int velY, int speed, sf::Texture tex);
        void setAnim(std::string strArgument);
        sf::Sprite sprite;
        int frame;
        int maxFrame;
        sf::IntRect rect;
        sf::Vector2f vel;
        int speed;
        bool alive;
        int activeAnim;
};

#endif // PARTICLES_H
