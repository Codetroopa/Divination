#include "BaseEnchantment.h"

BaseEnchantment::BaseEnchantment() : prev(NULL) {}


int BaseEnchantment::getAttack(int dmg) {
    if (prev) {
        return prev->getAttack(dmg);
    }
    return dmg;
}

int BaseEnchantment::getHp(int hp) {
    return hp;
}
