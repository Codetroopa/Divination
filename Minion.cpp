#include "Minion.h"

Minion::Minion(string name, int cost, int dmg, int maxHp) {
    this->name = name;
    this->maxHp = maxHp;
    this->hp = maxHp;
    this->dmg = dmg;
    this->cost = cost;
}

void Minion::remove() {

}

card_template_t Minion::asCardTemplate() {
    return display_minion_no_ability(name, cost, dmg, hp);
}
