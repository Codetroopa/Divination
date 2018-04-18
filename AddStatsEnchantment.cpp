#include "AddStatsEnchantment.h"

AddStatsEnchantment::AddStatsEnchantment(BaseEnchantment *b, int dmg, int hp) {
    this->prev = b;
    this->hpAmount = hp;
    this->dmgAmount = dmg;
}

int AddStatsEnchantment::getAttack(int baseDmg) {
    if (prev) {
        return prev->getAttack(baseDmg) + dmgAmount;
    }
    return baseDmg + dmgAmount;
}

int AddStatsEnchantment::getHp(int base) {
    return base + hpAmount;
}
