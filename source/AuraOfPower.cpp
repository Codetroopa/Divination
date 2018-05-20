#include "AuraOfPower.h"
#include "AddStatsEnchantment.h"

AuraOfPower::AuraOfPower(Player *p, string name, int cost, int ritualCost, int maxCharges, string description)
    : Ritual::Ritual(p, name, cost, ritualCost, maxCharges, description) { }

void AuraOfPower::onMinionPlayEffects(GameController *con, Minion *minion) {
    if (this->ritualCost > this->charges) {
        // do nothing
        return;
    }
    minion->addEnchantment(new AddStatsEnchantment(NULL, 1, 1));
    this->charges -= this->ritualCost;
}
