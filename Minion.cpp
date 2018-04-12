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

// Attack an opposing minion
void Minion::attack(Minion *other) {

}

// Attack the opposing Player
void Minion::attack(Player *p) {
    p->receiveDamage(calculateDamage());
}

int Minion::calculateDamage() {
    // TODO: This will have to take into affect any enchantments in the future
    return dmg;
}

card_template_t Minion::asCardTemplate() {
    return display_minion_no_ability(name, cost, dmg, hp);
}
