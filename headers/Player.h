#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <iostream>

using namespace std;

class Deck;
class Card;
class Minion;

class Player {
    int hp;
    int magic;
    int ownerNumber; // this is either 1 or 2 for Player 1 or 2
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
    Player(string name, int o, string deck);
    void drawCard();
    void playCard(int i);               // Play a card from hand at index i.
    void playCard(int i, int p, int j); // Play a card from hand at index i. Target Player p's jth minion
};

const int DEFAULT_HP = 20;
const int DEFAULT_MAGIC = 3;

#endif