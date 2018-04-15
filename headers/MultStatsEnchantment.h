#ifndef MULTSTATSENCHANTMENT_H
#define MULTSTATSENCHANTMENT_H
#include "AsciiGraphics.h"
#include "BaseEnchantment.h"

class MultStatsEnchantment : public BaseEnchantment{
    int hpMult;
    int dmgMult;

    public:
    MultStatsEnchantment(BaseEnchantment *prev, int dmgMult, int hpMult);
    int getAttack(int baseDmg);
    int getHp(int baseHp);
};

#endif
