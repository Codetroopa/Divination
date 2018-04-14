// Decorator pattern for implementing stat buffs for Minions
#ifndef BASE_ENCHANTMENT_H
#define BASE_ENCHANTMENT_H
#include "AsciiGraphics.h"

class BaseEnchantment {

    public:
    BaseEnchantment *prev;                  // A reference to the previous list of enchantments
    virtual int getAttack();
    virtual int getHp(int baseHp);
};

#endif
