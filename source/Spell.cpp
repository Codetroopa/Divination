#include "Spell.h"

Spell::Spell(Player *p, string name, int cost, string desc) {
    this->name = name;
    this->cost = cost;
    this->description = desc;
}

string Spell::getName() {
    return name;
}

card_template_t Spell::asCardTemplate() {
    return display_spell(name, cost, description);
}
