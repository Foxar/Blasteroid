#include <SFML/Graphics.hpp>
#include "bullet.h"
#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

sf::IntRect astRects[21];
sf::IntRect shipRects[2];
sf::IntRect muzzleRects[5][2];
sf::IntRect laser[1];

std::vector<bullet>bulletList;



#endif // GLOBAL_H_INCLUDED

