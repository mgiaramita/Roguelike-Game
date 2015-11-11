#ifndef TILE_H
#define TILE_H
#include <string>

using namespace std;

class Tile
{
    public:
        Tile();
        Tile(string t, string spec);  //type is main tile type, spec is the specifier for the exact tile type. ex (item, health)
        //Different types mob tiles, path tiles, item tiles, wall tiles, etc...
        virtual ~Tile();
        string getType();
        string getSpecifier();
        bool isActive();
        void setInactive();

    private:
        string type;  //Tile type
        string specifier;  //exact tile type item -> health or mob -> boss
        bool active;   //is tile active, for items/mobs if T acts normal if F acts as normal floor tile
};

#endif // TILE_H
