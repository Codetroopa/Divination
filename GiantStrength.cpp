#include "GiantStrength.h"

GiantStrength::GiantStrength(BaseEnchantment *b) {
    this->prev = b;
}

int GiantStrength::getAttack() {
    return prev->getAttack() + 2;
}

int GiantStrength::getHp(int base) {
    return base + 2;
}
