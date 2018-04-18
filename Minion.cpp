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
    this->hasAttacked = false;
    this->latestEnchantment = NULL;
}

// Attack an opposing minion then get hit back. (APNAP ordering)
bool Minion::attack(Minion *other) {
    if (hasAttacked) {
        cout << "The selected minion has already made a move this turn!" << endl;
        return false;
    }
    other->receiveDamage(calculateDamage());
    receiveDamage(other->calculateDamage());
    hasAttacked = true;
    return true;
}

// Attack the opposing Player
bool Minion::attack(Player *p) {
    if (hasAttacked) {
        cout << "The selected minion has already made a move this turn!" << endl;
        return false;
    }
    p->receiveDamage(calculateDamage());
    hasAttacked = true;
    return true;
}

int Minion::calculateDamage() {
    // TODO: This will have to take into affect any enchantments in the future
    if (latestEnchantment) {
        return latestEnchantment->getAttack(dmg);
    }
    return dmg;
}

void Minion::addEnchantment(BaseEnchantment *b) {
    if (latestEnchantment) {
        b->prev = latestEnchantment;
    }
    latestEnchantment = b;
    // We must immediately apply the Health enchantment
    hp = latestEnchantment->getHp(hp);
    maxHp = latestEnchantment->getHp(maxHp);
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
    // Move to graveyard with default stats
    player->graveyard.push(this);
    player->field.erase(fieldLocation(player->field));
    resetStats();
}

void Minion::kill() {
    die();
}

void Minion::resetStats() {
    // Remove all enchantments
    if (latestEnchantment) {
        delete latestEnchantment;
        latestEnchantment = NULL;
    }
    hp = startHp;
    dmg = startDmg;
}

void Minion::removeTopEnchantment() {
    if (!latestEnchantment) {
        return;
    }
    hp -= latestEnchantment->getHp(0);
    maxHp -= latestEnchantment->getHp(0);
    latestEnchantment = latestEnchantment->prev;
}

void Minion::endOfTurnEffects(GameController *con) {
    hasAttacked = false;
}

void Minion::startOfTurnEffects(GameController *con) {

}

card_template_t Minion::asCardTemplate() {
    return display_minion_no_ability(name, cost, calculateDamage(), hp);
}
