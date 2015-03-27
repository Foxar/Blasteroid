#include <SFML/Graphics.hpp>
#include "bullet.h"
#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

sf::IntRect astRects[21];

sf::IntRect shipRects[2][3];

sf::IntRect AshipRects[2];
sf::IntRect BshipRects[2];
sf::IntRect CshipRects[2];

sf::IntRect shipShootRects[5][2][3];

sf::IntRect AshipShootRects[5][2];
sf::IntRect BshipShootRects[5][2];
sf::IntRect CshipShootRects[5][2];

sf::IntRect plasma[1];

std::vector<bullet>bulletList;



#endif // GLOBAL_H_INCLUDED

