#ifndef MAGIC_FATIGUE_Enchantment_H
#define MAGIC_FATIGUE_Enchantment_H
#include "AsciiGraphics.h"
#include "BaseEnchantment.h"

class MagicFatigueEnchantment : public BaseEnchantment{
    int amount;

    public:
    MagicFatigueEnchantment(BaseEnchantment *prev, int amount);
    int getActivationCost(int baseFatigue);
};

#endif
