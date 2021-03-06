#ifndef NOVICE_PYRO_H
#define NOVICE_PYRO_H
#include "Player.h"
#include "GameController.h"
#include "AbilityMinion.h"
#include <iostream>
#include <vector>

using namespace std;

class NovicePyromancer : public AbilityMinion {
    public:
    NovicePyromancer(Player *p, string name, int cost, int dmg, int maxHp, int activationCost, string desc);
    virtual bool useAbility(GameController *con, Minion *m);
    virtual bool useAbility(GameController *con);
    virtual bool targetsMinion();
};

#endif