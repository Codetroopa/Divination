#include "MultStatsEnchantment.h"

MultStatsEnchantment::MultStatsEnchantment(BaseEnchantment *b, int dmg, int hp) {
    this->prev = b;
    this->dmgMult = dmg;
    this->hpMult = hp;
}

int MultStatsEnchantment::getAttack(int baseDmg) {
    if (prev) {
        return prev->getAttack(baseDmg) * dmgMult;
    }
    return baseDmg * dmgMult;
}

int MultStatsEnchantment::getHp(int base) {
    return base * hpMult;
}
