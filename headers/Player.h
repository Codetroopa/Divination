#ifndef PLAYER_H
#define PLAYER_H
#include "AsciiGraphics.h"
#include <vector>
#include <iostream>

using namespace std;

class Deck;
class Card;
class Minion;

class Player {
    int maxHp;
    int hp;
    int magic;
    string name;
    Deck *deck;
    Card *ritual;

    // private methods
    bool validCardIndex(int i);
    void addToField(Minion *m, int position);

    public:
    vector<Card *> hand;                // This Player's cards in hand
    vector<Minion *> field;             // This Player's minions in the field, and still alive
    vector<Minion *> graveyard;         // This Player's minions that have been killed
    int ownerNumber;                    // This is either 1 or 2 for Player 1 or 2
    Player(string name, int o, string deck);
    void drawCard();
    bool playCard(int i);               // Play a card from hand at index i.
    bool playCard(int i, int p, int j); // Play a card from hand at index i. Target Player p's jth minion
    void receiveDamage(int dmg);
    void gainMagic(int amount);
    card_template_t asPortrait();       // Display as a card_template_t
};

const int DEFAULT_HP = 20;
const int DEFAULT_MAGIC = 3;

#endif