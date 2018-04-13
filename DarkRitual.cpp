#include "DarkRitual.h"

DarkRitual::DarkRitual(Player *p, string name, int cost, int ritualCost, int maxCharges, string description)
    : Ritual::Ritual(p, name, cost, ritualCost, maxCharges, description) { }

void DarkRitual::startOfTurnEffects(GameController *con) {
    if (this->ritualCost > this->charges) {
        // do nothing
        return;
    }
    con->addMana(1);
    this->charges -= this->ritualCost;
}
