#ifndef MINION_H
#define MINION_H
#include "Card.h"
#include <iostream>

using namespace std;

class Minion : public Card {
    int maxHp;
    int hp;
    int dmg;

    public:

    Minion(string name, int maxHp, int dmg);
    void remove();
};

#endif