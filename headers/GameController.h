#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "Minion.h"
#include "Player.h"
#include "Spell.h"
#include "Ritual.h"
#include "AsciiGraphics.h"
#include <iostream>
#include <sstream>

using namespace std;

class GameController {
    // Private Variables
    Player *activePlayer;
    Player *nonActivePlayer;
    bool testing = false;
    int turn;                   // Whose turn is it anyways?

    // Private Methods
    void displayHelpMessage();
    void displayCardTemplates(vector<card_template_t> &cards, bool withBorder);
    bool makeAttack(int i);
    bool makeAttack(int i, int j);

    // Public Methods
    public:

    GameController(string p1, string p2, string d1, string d2, bool testing = false);
    void play();
    void drawBoard();
    void drawHand();
    void nextTurn();
    void removeMinionToOwnersDeck(Minion *m);
    void onMinionPlayed(Minion *);
    void damageOpposingMinions(int amount);
    void addMana(int amount, bool activePlayer = true);

    // if mustHaveRoom is true, this will fail unless there is enough space for ALL minions
    bool summonMinions(string name, int num, int dmg, int hp, bool mustHaveRoom = false);
};

#endif