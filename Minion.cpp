#include "Minion.h"

Minion::Minion(Player *p, string name, int cost, int dmg, int maxHp) {
    this->name = name;
    this->startHp = maxHp;
    this->maxHp = maxHp;
    this->hp = maxHp;
    this->startDmg = dmg;
    this->dmg = dmg;
    this->cost = cost;
    this->player = p;
}

void Minion::remove() {

}

// Attack an opposing minion then get hit back. (APNAP ordering)
void Minion::attack(Minion *other) {
    other->receiveDamage(calculateDamage());
    receiveDamage(other->calculateDamage());
}

// Attack the opposing Player
void Minion::attack(Player *p) {
    p->receiveDamage(calculateDamage());
}

int Minion::calculateDamage() {
    // TODO: This will have to take into affect any enchantments in the future
    return dmg;
}

void Minion::receiveDamage(int amount) {
    hp -= amount;
    if (hp <= 0) {
        die();
    }
}

vector<Minion *>::iterator Minion::fieldLocation(vector<Minion *> &field) {
    for (vector<Minion *>::iterator it = field.begin(); it < field.end(); it++) {
        if (*it == this) {
            return it;
        }
    }
    cout << "Error: Can't delete this minion " << name << endl;
    exit(1);
    return field.begin();
}

void Minion::die() {
    player->graveyard.push(this);
    player->field.erase(fieldLocation(player->field));
    hp = startHp;
    dmg = startDmg;
}

card_template_t Minion::asCardTemplate() {
    return display_minion_no_ability(name, cost, dmg, hp);
}
