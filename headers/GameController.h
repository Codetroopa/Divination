#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "Board.h"
#include <iostream>

using namespace std;

class Player;

class GameController {
    // Private Variables
    Board *board;
    Player *activePlayer;
    Player *nonActivePlayer;

    // Private Methods
    void displayHelpMessage();

    // Public Methods
    public:

    GameController(string p1, string p2, string d1, string d2);
    void play();

};

#endif