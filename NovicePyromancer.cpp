#include "NovicePyromancer.h"

NovicePyromancer::NovicePyromancer(Player *p, string name, int cost, int dmg, int maxHp, int activationCost, string desc)
    : AbilityMinion::AbilityMinion(p, name, cost, dmg, maxHp, activationCost, desc) { }

bool NovicePyromancer::useAbility(GameController *con, Minion *m) {
    hasAttacked = true;
    m->receiveDamage(1);
    return true;
}

bool NovicePyromancer::useAbility(GameController *con) { return false; }

bool NovicePyromancer::targetsMinion() {
    return true;
}
