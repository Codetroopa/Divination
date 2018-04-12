#ifndef MINION_H
#define MINION_H
#include "Card.h"
#include "Player.h"
#include <iostream>

using namespace std;

class Minion : public Card {
    int maxHp;
    int hp;
    int dmg;
    int cost;

    int calculateDamage();

    public:

    Minion(string name, int cost, int dmg, int maxHp);
    void remove();
    virtual void attack(Minion *other);
    virtual void attack(Player *other);
    card_template_t asCardTemplate();
};

#endif