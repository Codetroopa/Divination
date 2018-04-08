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
    Card *drawCard();
};

// Temporary hard constant
const string DEFAULT_DECK = "Air Elemental\n"
"Earth Elemental\n"
"Fire Elemental\n"
"Potion Seller\n"
"Novice Pyromancer\n"
"Apprentice Summoner\n"
"Master Summoner\n"
"Banish\n"
"Unsummon\n"
"Recharge\n"
"Disenchant\n"
"Raise Dead\n"
"Blizzard\n"
"Giant Strength\n"
"Magic Fatigue\n"
"Silence\n"
"Dark Ritual\n"
"Aura of Power\n"
"Standstill\n";

#endif