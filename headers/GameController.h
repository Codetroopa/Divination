#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "Minion.h"
#include "AsciiGraphics.h"
#include <iostream>

using namespace std;

class Player;

class GameController {
    // Private Variables
    Player *activePlayer;
    Player *nonActivePlayer;
    int turn;

    // Private Methods
    void displayHelpMessage();
    void displayCardTemplates(vector<card_template_t> &cards);

    // Public Methods
    public:

    GameController(string p1, string p2, string d1, string d2);
    void play();
    void drawBoard();
    void nextTurn();
    int whoseTurn();                         // Whose turn is it anyway?
};

#endif