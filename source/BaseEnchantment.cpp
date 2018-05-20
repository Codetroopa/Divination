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

int BaseEnchantment::getActivationCost(int baseActivation) {
    if (prev) {
        return prev->getActivationCost(baseActivation);
    }
    return baseActivation;
}

bool BaseEnchantment::isSilenced(bool defaultFlag) {
    if (prev) {
        return prev->isSilenced(defaultFlag);
    }
    return defaultFlag;
}
