#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "Minion.h"
#include "AsciiGraphics.h"
#include <iostream>
#include <sstream>

using namespace std;

class Player;

class GameController {
    // Private Variables
    Player *activePlayer;
    Player *nonActivePlayer;
    int turn;                   // Whose turn is it anyways?

    // Private Methods
    void displayHelpMessage();
    void displayCardTemplates(vector<card_template_t> &cards);
    bool makeAttack(int i);

    // Public Methods
    public:

    GameController(string p1, string p2, string d1, string d2);
    void play();
    void drawBoard();
    void nextTurn();
};

#endif