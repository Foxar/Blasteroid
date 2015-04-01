#include <SFML/Graphics.hpp>
#include "bullet.h"
#include "asteroid.h"
#include "particles.h"
#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED


 sf::IntRect astRects[21];

 sf::IntRect shipRects[2]; //ENGINE

 sf::IntRect playerShipRects[2];

 sf::IntRect shipShootRects[5][2]; //FRAME ENGINE

 sf::IntRect playerShipShootRects[5][2][2];

 sf::IntRect plasma[1];

 sf::IntRect explRect[6];

std::vector<bullet>bulletList;
std::vector<particles>partList;
std::vector<asteroid>astList;



#endif // GLOBAL_H_INCLUDED

