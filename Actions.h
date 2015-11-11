#ifndef ACTIONS_H
#define ACTIONS_H
#include "Map.h"
#include "Player.h"
#include <stdlib.h>

using namespace std;

class Actions
{
    public:
        Actions();
        virtual ~Actions();
        void moveW();
        void moveA();
        void moveS();
        void moveD();
        void attack();
        void openInv();

        bool getActiveStatus();

    //private:
        Map* m1;
        Player* p1;
};

#endif // ACTIONS_H
