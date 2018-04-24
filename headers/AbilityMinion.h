#ifndef ABILITY_MINION_H
#define ABILITY_MINION_H
#include "Player.h"
#include "GameController.h"
#include "Minion.h"
#include "AsciiGraphics.h"
#include <iostream>
#include <vector>

using namespace std;

class AbilityMinion : public Minion {
    protected:
    string description;
    int activationCost;

    public:
    AbilityMinion(Player *p, string name, int cost, int dmg, int maxHp, int activationCost, string desc);
    virtual bool useAbility(GameController *con, Minion *m) { return false; }
    virtual bool useAbility(GameController *con) { return false; }
    virtual bool targetsMinion() {return true; }

    card_template_t asCardTemplate();
};

#endif