#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Items.h"
#include <stdlib.h>

using namespace std;

class Player
{
    public:
        Player();
        virtual ~Player();

        int getXPos();
        int getYPos();
        void setXPos(int x);
        void setYPos(int y);
        void setHealth(int change);

        void printHud();
        void printInv();
        int inv[5];  //position 0 = health, 1 = fist, 2 = club, 3 = sword, 4 = key

    private:
        int xPos;
        int yPos;
        int health;
        string weapon;
};

#endif // PLAYER_H
