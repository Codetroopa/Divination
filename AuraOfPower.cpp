#include "AuraOfPower.h"

AuraOfPower::AuraOfPower(Player *p, string name, int cost, int ritualCost, int maxCharges, string description)
    : Ritual::Ritual(p, name, cost, ritualCost, maxCharges, description) { }

void AuraOfPower::onMinionPlayEffects(GameController *con, Minion *minion) {
    if (this->ritualCost > this->charges) {
        // do nothing
        return;
    }
    // TODO Buff minion here
    this->charges -= this->ritualCost;
}
