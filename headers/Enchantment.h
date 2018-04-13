// Decorator pattern for implementing stat buffs for Minions
#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H
#include "AsciiGraphics.h"
#include "Minion.h"

class StatBuffs {


    public:
    virtual void getAttack() = 0;
};

#endif
