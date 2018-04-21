#ifndef FIRE_ELEMENTAL_H
#define FIRE_ELEMENTAL_H

#include "TriggerMinion.h"
#include <iostream>

using namespace std;

class FireElemental : public TriggerMinion {

    public:
    FireElemental(Player *p, string name, int cost, int dmg, int maxHp, string desc);
    void onMinionPlayEffects(GameController *con, Minion *m);
};

#endif
