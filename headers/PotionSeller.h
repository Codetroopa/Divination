#ifndef POTION_SELLER_H
#define POTION_SELLER_H

#include "TriggerMinion.h"
#include <iostream>

using namespace std;

class PotionSeller : public TriggerMinion {

    public:
    PotionSeller(Player *p, string name, int cost, int dmg, int maxHp, string desc);
    void endOfTurnEffects(GameController *con);
};

#endif
