#include "ColossalStrength.h"

ColossalStrength::ColossalStrength(BaseEnchantment *b) {
    this->prev = b;
}

int ColossalStrength::getAttack() {
    return prev->getAttack() * 2;
}

int ColossalStrength::getHp(int base) {
    return base * 2;
}
