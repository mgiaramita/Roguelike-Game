#include "Map.h"
#include <stdlib.h>

Map::Map()  //Level 1
{
    mapX = 20;
    mapY = 10;

    Tile *t1 = new Tile("path", "none");
    map1[0][0] = *t1; map1[1][0] = *t1; map1[2][0] = *t1; map1[3][0] = *t1; map1[5][0] = *t1; map1[6][0] = *t1; map1[7][0] = *t1; map1[8][0] = *t1; map1[9][0] = *t1; map1[11][0] = *t1; map1[17][0] = *t1;
    map1[0][1] = *t1; map1[3][1] = *t1; map1[5][1] = *t1; map1[11][1] = *t1; map1[12][1] = *t1; map1[13][1] = *t1; map1[14][1] = *t1; map1[15][1] = *t1; map1[16][1] = *t1; map1[17][1] = *t1; map1[18][1] = *t1; map1[19][1] = *t1;
    map1[0][2] = *t1; map1[3][2] = *t1; map1[4][2] = *t1; map1[5][2] = *t1; map1[9][2] = *t1; map1[10][2] = *t1; map1[13][2] = *t1; map1[19][2] = *t1;
    map1[0][3] = *t1; map1[4][3] = *t1; map1[13][3] = *t1; map1[15][3] = *t1; map1[16][3] = *t1; map1[17][3] = *t1; map1[19][3] = *t1;
    map1[1][4] = *t1; map1[4][4] = *t1; map1[10][4] = *t1; map1[13][4] = *t1; map1[15][4] = *t1; map1[17][4] = *t1; map1[19][4] = *t1;
    map1[0][5] = *t1; map1[1][5] = *t1; map1[2][5] = *t1; map1[4][5] = *t1; map1[5][5] = *t1; map1[8][5] = *t1; map1[9][5] = *t1; map1[10][5] = *t1; map1[12][5] = *t1; map1[13][5] = *t1; map1[15][5] = *t1; map1[17][5] = *t1; map1[18][5] = *t1;
    map1[4][6] = *t1; map1[8][6] = *t1; map1[13][6] = *t1; map1[19][6] = *t1;
    map1[3][7] = *t1; map1[4][7] = *t1; map1[7][7] = *t1; map1[8][7] = *t1; map1[9][7] = *t1; map1[10][7] = *t1; map1[13][7] = *t1; map1[19][7] = *t1;
    map1[2][8] = *t1; map1[3][8] = *t1; map1[8][8] = *t1; map1[13][8] = *t1; map1[14][8] = *t1; map1[15][8] = *t1; map1[16][8] = *t1;
    map1[8][9] = *t1;

    Tile *t2 = new Tile("mob", "norm"); map1[10][0] = *t2;
    Tile *t3 = new Tile("mob", "norm"); map1[9][1] = *t3; Tile *t4 = new Tile("mob", "norm"); map1[10][1] = *t4;
    Tile *t5 = new Tile("mob", "norm"); map1[0][4] = *t5;
    Tile *t6 = new Tile("mob", "norm"); map1[19][5] = *t6;
    Tile *t7 = new Tile("mob", "norm"); map1[10][8] = *t7; Tile *t8 = new Tile("mob", "norm"); map1[17][8] = *t8;

    Tile *t9 = new Tile("item", "health"); map1[11][2] = *t9;
    Tile *t10 = new Tile("item", "club"); map1[2][4] = *t10;
    Tile *t11 = new Tile("item", "sword"); map1[6][7] = *t11;
    Tile *t12 = new Tile("item", "key"); map1[1][8] = *t12; Tile *t13 = new Tile("item", "health"); map1[19][8] = *t13;

    Tile *t14 = new Tile("path", "blocked"); map1[18][8] = *t14;

    Tile *t15 = new Tile("door", "locked"); map1[10][3] = *t15;

    Tile *t16 = new Tile("mob", "boss"); map1[15][6] = *t16;
}

Map::~Map(){}

int Map::getMapY(){
    return mapY;
}

int Map::getMapX(){
    return mapX;
}

void Map::printMap(int x, int y){
    system("cls");

    cout << "First Test Build of New Game" << endl;
    cout << "Use WASD keys to move around map and q to exit" << endl;
    cout << "To attack an enemy press r" << endl;
    cout << "Player location is marked by the '&' on the map" << endl;
    cout << "\n";

    for(int i = 0; i < mapX + 2; i++){  //Print top outer wall
        cout << "####";
    }
    cout << "\n";
    for(int i = 0; i < mapX + 2; i++){
        cout << "####";
    }
    cout << "\n";

    for(int i = 0; i < mapY; i++){
        cout << "####";  //Left outer wall
        for(int j = 0; j < mapX; j++){
            Tile tempTile = map1[j][i];
            if(i == y && j == x){  //if player is at (j, k)
                cout << " && ";
            }
            else if(tempTile.getType() == "Wall"){
                cout << "####";
            }
            else{
                cout << "    ";
            }
        }
        cout << "####";   //Right outer wall
        cout << "\n";

        cout << "####";  //Left outer wall
        for(int j = 0; j < mapX; j++){
            Tile tempTile = map1[j][i];
            if(i == y && j == x){  //if player is at (j, k)
                cout << " && ";
            }
            else if(tempTile.getType() == "Wall"){
                cout << "####";
            }
            else{
                cout << "    ";
            }
        }
        cout << "####";   //Right outer wall
        cout << "\n";
    }

    for(int i = 0; i < mapX + 2; i++){   //Lower outer wall
        cout << "####";
    }
    cout << "\n";
    for(int i = 0; i < mapX + 2; i++){   //Lower outer wall
        cout << "####";
    }
    cout << "\n";
}
