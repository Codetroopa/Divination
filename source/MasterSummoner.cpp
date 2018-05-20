#include "MasterSummoner.h"

MasterSummoner::MasterSummoner(Player *p, string name, int cost, int dmg, int maxHp, int activationCost, string desc)
    : AbilityMinion::AbilityMinion(p, name, cost, dmg, maxHp, activationCost, desc) { }

bool MasterSummoner::useAbility(GameController *con, Minion *m) { return false; }

bool MasterSummoner::useAbility(GameController *con) {
    bool success = con->summonMinions("Air Elemental", 3, 1, 1);
    hasAttacked = success;
    return success;
}

bool MasterSummoner::targetsMinion() {
    return false;
}
