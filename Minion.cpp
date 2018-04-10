#include "Minion.h"

Minion::Minion(string name, int maxHp, int dmg) {
    this->name = name;
    this->maxHp = maxHp;
    this->hp = maxHp;
    this->dmg = dmg;
}

void Minion::remove() {

}

card_template_t Minion::asCardTemplate() {
    return display_minion_no_ability(name, cost, dmg, hp);
}
