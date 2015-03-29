#include <SFML/Graphics.hpp>
#include "rectController.h"

void setRects()
{
    shipRects[0] = sf::IntRect(278, 176, 28, 33);
    shipRects[1] = sf::IntRect(233, 176, 28, 37);


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

    playerShipShootRects[0][0] = sf::IntRect(227, 264, 40, 40);    //SHIP=2 ENGINE=OFF FRAME=1
    playerShipShootRects[1][0] = sf::IntRect(228, 220, 40, 40);    //SHIP=2 ENGINE=ON FRAME=1
    playerShipShootRects[0][1] = sf::IntRect(271, 265, 40, 40);    //SHIP=2 ENGINE=OFF FRAME=2
    playerShipShootRects[1][1] = sf::IntRect(272, 220, 40, 40);    //SHIP=2 ENGINE=ON FRAME=2
    playerShipShootRects[0][2] = sf::IntRect(312, 264, 40, 40);    //SHIP=2 ENGINE=OFF FRAME=3
    playerShipShootRects[1][2] = sf::IntRect(313, 220, 40, 40);    //SHIP=2 ENGINE=ON FRAME=3
    playerShipShootRects[0][3] = sf::IntRect(356, 264, 40, 40);    //SHIP=2 ENGINE=OFF FRAME=4
    playerShipShootRects[1][3] = sf::IntRect(357, 220, 40, 40);    //SHIP=2 ENGINE=ON FRAME=4
    playerShipShootRects[0][4] = sf::IntRect(399, 264, 40, 40);    //SHIP=2 ENGINE=OFF FRAME=5
    playerShipShootRects[1][4] = sf::IntRect(400, 220, 40, 40);    //SHIP=2 ENGINE=ON FRAME=5



    plasma[0] = sf::IntRect(152, 173, 6, 13);

}

