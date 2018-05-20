#include "FireElemental.h"

FireElemental::FireElemental(Player *p, string name, int cost, int dmg, int maxHp, string desc)
    : TriggerMinion::TriggerMinion(p, name, cost, dmg, maxHp, desc) {}


void FireElemental::onMinionPlayEffects(GameController *con, Minion *m) {
    // Only target enemy minions
    if (player->isFriendlyMinion(m)) {
        return;
    }
    m->receiveDamage(1);
}
