#ifndef ROYAL_GUARD_H
#define ROYAL_GUARD_H

#include "TriggerMinion.h"
#include <iostream>

using namespace std;

class RoyalGuard : public TriggerMinion {

    public:
    RoyalGuard(Player *p, string name, int cost, int dmg, int maxHp, string desc);
    void deathrattle(GameController *con);
};

#endif
