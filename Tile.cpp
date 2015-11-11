#include "Tile.h"

Tile::Tile()
{
    type = "Wall";
    active = true;
}

Tile::Tile(string t, string spec){
    type = t;
    specifier = spec;
    active = true;
    //if type mob create mod type m1 to call functions on mobs when attacked
    /*if type item the player will have a bag that has n slots (where n is the number of item types available in the game).
      default value for these items will be zero. as found in dungeon the number will increase. when used they will decrease.
      remove need for items class/object */
}

Tile::~Tile(){}

string Tile::getType(){
    return type;
}

string Tile::getSpecifier(){
    return specifier;
}

bool Tile::isActive(){
    return active;
}

void Tile::setInactive(){
    active = false;
}
