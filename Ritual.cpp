#include "Ritual.h"

Ritual::Ritual(Player *p, string name, int cost, int ritualCost, int maxCharges, string description) {
    this->ritualCost = ritualCost;
    this->charges = maxCharges;
    this->maxCharges = maxCharges;
    this->description = description;
    this->name = name;
    this->cost = cost;
    this->player = p;
}

card_template_t Ritual::asCardTemplate() {
    return display_ritual(name, cost, ritualCost, description, charges);
}
