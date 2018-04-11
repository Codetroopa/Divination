#ifndef MINION_H
#define MINION_H
#include "Card.h"
#include <iostream>

using namespace std;

class Minion : public Card {
    int maxHp;
    int hp;
    int dmg;
    int cost;

    public:

    Minion(string name, int cost, int dmg, int maxHp);
    void remove();
    card_template_t asCardTemplate();
};

#endif