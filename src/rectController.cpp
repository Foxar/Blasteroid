#include <SFML/Graphics.hpp>
#include "rectController.h"

void setRects()
{
    shipRects[0] = sf::IntRect(70, 149, 36, 49);
    shipRects[1] = sf::IntRect(30, 149, 36, 49);

    astRects[0] = sf::IntRect(4, 105, 17, 17);
    astRects[1] = sf::IntRect(28, 106, 13, 15);
    astRects[2] = sf::IntRect(48, 105, 12, 17);
    astRects[3] = sf::IntRect(57, 92, 14, 10);
    astRects[4] = sf::IntRect(79, 104, 11, 11);
    astRects[5] = sf::IntRect(97, 105, 15, 16);
    astRects[6] = sf::IntRect(119, 110, 11, 11);
    astRects[7] = sf::IntRect(133, 105, 11, 14);
    astRects[8] = sf::IntRect(164, 113, 14, 11);
    astRects[9] = sf::IntRect(179, 105, 17, 17);
    astRects[10] = sf::IntRect(4, 113, 15, 16);
    astRects[11] = sf::IntRect(214, 110, 10, 20);
    astRects[12] = sf::IntRect(228, 109, 12, 21);
    astRects[13] = sf::IntRect(11, 61, 32, 28);
    astRects[14] = sf::IntRect(52, 56, 22, 25);
    astRects[15] = sf::IntRect(84, 61, 32, 30);
    astRects[16] = sf::IntRect(120, 62, 21, 26);
    astRects[17] = sf::IntRect(160, 70, 40, 34);
    astRects[18] = sf::IntRect(17, 2, 69, 45);
    astRects[19] = sf::IntRect(98, 2, 54, 47);
    astRects[20] = sf::IntRect(174, 6, 71, 52);

    muzzleRects[0][0] = sf::IntRect(4, 202, 36, 46);
    muzzleRects[1][0] = sf::IntRect(42, 202, 36, 46);
    muzzleRects[2][0] = sf::IntRect(79, 202, 36, 46);
    muzzleRects[3][0] = sf::IntRect(116, 202, 36, 46);
    muzzleRects[4][0] = sf::IntRect(153, 202, 36, 46);

    muzzleRects[0][1] = sf::IntRect(4, 251, 36, 50);
    muzzleRects[1][1] = sf::IntRect(42, 251, 36, 50);
    muzzleRects[2][1] = sf::IntRect(79, 251, 36, 50);
    muzzleRects[3][1] = sf::IntRect(116, 251, 36, 50);
    muzzleRects[4][1] = sf::IntRect(153, 251, 36, 50);

    laser[0] = sf::IntRect(152, 173, 6, 13);

}

