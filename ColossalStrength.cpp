#include "ColossalStrength.h"

ColossalStrength::ColossalStrength(BaseEnchantment *b) {
    this->prev = b;
}

int ColossalStrength::getAttack(int baseDmg) {
    if (prev) {
        return prev->getAttack(baseDmg) * 2;
    }
    return baseDmg * 2;
}

int ColossalStrength::getHp(int base) {
    return base * 2;
}
