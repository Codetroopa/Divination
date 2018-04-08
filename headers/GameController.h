#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "Board.h"
#include <iostream>

class GameController {
    // Private Variables
    Board *board;

    // Private Methods
    void displayHelpMessage();
    public:

    void play();

};

#endif