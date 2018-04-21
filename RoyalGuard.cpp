#include "RoyalGuard.h"

RoyalGuard::RoyalGuard(Player *p, string name, int cost, int dmg, int maxHp, string desc)
    : TriggerMinion::TriggerMinion(p, name, cost, dmg, maxHp, desc) {}


void RoyalGuard::deathrattle(GameController *con) {
    TriggerMinion::die();
    player->restoreHealth(4);
}
