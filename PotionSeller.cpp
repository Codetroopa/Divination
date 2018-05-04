#include "PotionSeller.h"
#include "AddStatsEnchantment.h"

PotionSeller::PotionSeller(Player *p, string name, int cost, int dmg, int maxHp, string desc)
    : TriggerMinion::TriggerMinion(p, name, cost, dmg, maxHp, desc) {}


void PotionSeller::endOfTurnEffects(GameController *con) {
    player->enchantAllFriendlyMinions(NULL);
}
