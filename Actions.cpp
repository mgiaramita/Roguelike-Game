#include "Actions.h"

Actions::Actions(){
    m1 = new Map();
    p1 = new Player();
}

Actions::~Actions(){}

bool Actions::getActiveStatus(){
    return m1->map1[p1->getXPos()][p1->getYPos()].isActive();
}

void Actions::moveW(){
    int xPos = p1->getXPos();  //get the players current position on the map
    int yPos = p1->getYPos();
    if(m1->map1[p1->getXPos()][p1->getYPos()].getType() == "mob" && getActiveStatus() == true){  //If the tile is of type mob and it is active(enemy not defeated)
        cout << "No Running! Kill the enemy." << endl;
    }
    else if(yPos == 0 || m1->map1[p1->getXPos()][p1->getYPos() - 1].getType() == "Wall"){  //If out of bounds or tile is wall
        cout << "You can't walk in that direction." << endl;
    }
    else{  //okay to move
        p1->setYPos(yPos - 1);  //move one space corresponding to the key direction
        m1->printMap(p1->getXPos(), p1->getYPos());  //reprint map and HUD to show player movement
        p1->printHud();

        if(m1->map1[p1->getXPos()][p1->getYPos()].getType() == "mob" && getActiveStatus() == true){
            cout << "You have encountered an enemy! Fight or die..." << endl;
        }
    }
}

void Actions::moveA(){
    int xPos = p1->getXPos();
    int yPos = p1->getYPos();
    if(m1->map1[p1->getXPos()][p1->getYPos()].getType() == "mob" && getActiveStatus() == true){
        cout << "No Running! Kill the enemy." << endl;
    }
    else if(xPos == 0 || m1->map1[p1->getXPos() - 1][p1->getYPos()].getType() == "Wall"){
        cout << "You can't walk in that direction." << endl;
    }
    else{
        p1->setXPos(xPos - 1);
        m1->printMap(p1->getXPos(), p1->getYPos());
        p1->printHud();

        if(m1->map1[p1->getXPos()][p1->getYPos()].getType() == "mob" && getActiveStatus() == true){
            cout << "You have encountered an enemy! Fight or die..." << endl;
        }
    }
}

void Actions::moveS(){
    int xPos = p1->getXPos();
    int yPos = p1->getYPos();
    if(m1->map1[p1->getXPos()][p1->getYPos()].getType() == "mob" && getActiveStatus() == true){
        cout << "No Running! Kill the enemy." << endl;
    }
    else if(yPos == (m1->getMapY() - 1) || m1->map1[p1->getXPos()][p1->getYPos() + 1].getType() == "Wall"){
        cout << "You can't walk in that direction." << endl;
    }
    else{
        p1->setYPos(yPos + 1);
        m1->printMap(p1->getXPos(), p1->getYPos());
        p1->printHud();

        if(m1->map1[p1->getXPos()][p1->getYPos()].getType() == "mob" && getActiveStatus() == true){
            cout << "You have encountered an enemy! Fight or die..." << endl;
        }
    }
}

void Actions::moveD(){
    int xPos = p1->getXPos();
    int yPos = p1->getYPos();
    if(m1->map1[p1->getXPos()][p1->getYPos()].getType() == "mob" && getActiveStatus() == true){
        cout << "No Running! Kill the enemy." << endl;
    }
    else if(xPos == (m1->getMapX() - 1) || m1->map1[p1->getXPos() + 1][p1->getYPos()].getType() == "Wall"){
        cout << "You can't walk in that direction." << endl;
    }
    else{
        p1->setXPos(xPos + 1);
        m1->printMap(p1->getXPos(), p1->getYPos());
        p1->printHud();

        if(m1->map1[p1->getXPos()][p1->getYPos()].getType() == "mob" && getActiveStatus() == true){
            cout << "You have encountered an enemy! Fight or die..." << endl;
        }
    }
}

void Actions::attack(){
    int xPos = p1->getXPos();
    int yPos = p1->getYPos();
    if(m1->map1[p1->getXPos()][p1->getYPos()].getType() == "mob" && getActiveStatus() == true){
        int chance = rand() % 100;     //generate a random number 0-99

        if(m1->map1[xPos][yPos].getSpecifier() == "norm"){  //if normal mob (not boss)
            if(chance%2 == 0){                 //30% chance that your attack will miss and you will take damage from the enemy
                p1->setHealth(-25);          //The enemy will take 25% of your health from this command: heath (out of 100) += -25
                m1->printMap(p1->getXPos(), p1->getYPos());   //reprint the map and HUD to show the effect that the damage has on your hearts
                p1->printHud();
                cout << "Your attack missed! You took damage!\n";

            }
            else{
                m1->map1[xPos][yPos].setInactive();    //The attack was successful the enemy will die and the tile will act as floor
                cout << "You defeated the enemy and can continue on.\n";
            }
        }

        else{   //If mob is the level boss
            if(chance%2 == 1){
                p1->setHealth(-25);
                m1->printMap(p1->getXPos(), p1->getYPos());
                p1->printHud();
                cout << "Your attack missed! You took damage!\n";

            }
            else{
                m1->map1[xPos][yPos].setInactive();    //The attack was successful the enemy will die and the tile will act as floor
                cout << "You defeated the enemy and can continue on.\n";
            }
        }
    }
    else{
        cout << "Nothing to attack. What a waste of energy..." << endl;   //if the tile you are on is not a mod type the command will have no effect
    }
}

void Actions::openInv(){
    p1->printInv();
}
