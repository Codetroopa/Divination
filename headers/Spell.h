#ifndef SPELL_H
#define SPELL_H
#include "Card.h"
#include "Player.h"
#include "AsciiGraphics.h"
#include <iostream>

using namespace std;

class Spell : public Card {
    string description;

    public:
    Spell(Player *p, string name, int cost, string desc);
    string getName();
    card_template_t asCardTemplate();
};

#endif