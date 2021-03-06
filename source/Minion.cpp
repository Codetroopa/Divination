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
    // We have to calculate before attacking in case effects resolve (like dying)
    int damageTaken = other->calculateDamage();
    other->receiveDamage(calculateDamage());
    receiveDamage(damageTaken);
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

bool Minion::attacked() {
    return hasAttacked;
}

int Minion::calculateDamage() {
    if (latestEnchantment) {
        return latestEnchantment->getAttack(dmg);
    }
    return dmg;
}

void Minion::addEnchantment(BaseEnchantment *b) {
    cout << "Adding enchantment: " << b << endl;
    if (latestEnchantment) {
        b->prev = latestEnchantment;
    }
    latestEnchantment = b;
    // We must immediately apply the Health enchantment
    hp = latestEnchantment->getHp(hp);
    maxHp = latestEnchantment->getHp(maxHp);
}


void Minion::receiveDamage(int amount) {
    if (dead) {
        return;
    }
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
    dead = true;
    resetStats();
}

void Minion::kill() {
    if (!dead) {
        die();
    }
}

// ensure all stats are ready to go for rebirth
void Minion::revive() {
    dead = false;
}

bool Minion::isDead() {
    return dead;
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
