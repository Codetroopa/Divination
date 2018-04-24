#include "ApprenticeSummoner.h"

ApprenticeSummoner::ApprenticeSummoner(Player *p, string name, int cost, int dmg, int maxHp, int activationCost, string desc)
    : AbilityMinion::AbilityMinion(p, name, cost, dmg, maxHp, activationCost, desc) { }

bool ApprenticeSummoner::useAbility(GameController *con, Minion *m) { return false; }

bool ApprenticeSummoner::useAbility(GameController *con) {
    bool success = con->summonMinions("Air Elemental", 1, 1, 1, true);
    hasAttacked = success;
    return success;
}

bool ApprenticeSummoner::targetsMinion() {
    return false;
}
