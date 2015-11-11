#ifndef MAP_H
#define MAP_H
#include <iostream>
#include "Tile.h"
#include "Player.h"

using namespace std;

class Map
{
    public:
        Map();
        virtual ~Map();
        void printMap(int x, int y);  //given player x and y pos
        int getMapX();
        int getMapY();

        Tile map1[20][10];

    private:
        int mapX;
        int mapY;
};

#endif // MAP_H
