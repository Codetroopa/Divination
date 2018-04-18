#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Deck {
    Player *owner;
    vector<Card *> cards;

    public:
    Deck(string filePath, Player *p);
    void shuffle();
    bool hasCards();
    Card *drawCard();
    void addToFront(Card *c);
};

#endif