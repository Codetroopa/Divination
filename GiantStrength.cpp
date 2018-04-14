#include "GiantStrength.h"

GiantStrength::GiantStrength(BaseEnchantment *b) {
    this->prev = b;
}

int GiantStrength::getAttack(int baseDmg) {
    if (prev) {
        return prev->getAttack(baseDmg) + 2;
    }
    return baseDmg + 2;
}

int GiantStrength::getHp(int base) {
    return base + 2;
}
