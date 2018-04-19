#include "Standstill.h"

Standstill::Standstill(Player *p, string name, int cost, int ritualCost, int maxCharges, string description)
    : Ritual::Ritual(p, name, cost, ritualCost, maxCharges, description) { }

void Standstill::onMinionPlayEffects(GameController *con, Minion *minion) {
    if (this->ritualCost > this->charges) {
        // do nothing
        return;
    }
    minion->kill();
    this->charges -= this->ritualCost;
}
