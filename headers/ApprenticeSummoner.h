#ifndef APPRENTICE_SUMMONER_H
#define APPRENTICE_SUMMONER_H
#include "Player.h"
#include "GameController.h"
#include "AbilityMinion.h"
#include <iostream>
#include <vector>

using namespace std;

class ApprenticeSummoner : public AbilityMinion {
    public:
    ApprenticeSummoner(Player *p, string name, int cost, int dmg, int maxHp, int activationCost, string desc);
    virtual bool useAbility(GameController *con, Minion *m);
    virtual bool useAbility(GameController *con);
    virtual bool targetsMinion();
};

#endif