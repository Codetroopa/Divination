#ifndef AddStatsEnchantment_H
#define AddStatsEnchantment_H
#include "AsciiGraphics.h"
#include "BaseEnchantment.h"

class AddStatsEnchantment : public BaseEnchantment{
    int hpAmount;
    int dmgAmount;

    public:
    AddStatsEnchantment(BaseEnchantment *prev, int dmgAmount, int hpAmount);
    int getAttack(int baseDmg);
    int getHp(int baseHp);
};

#endif
