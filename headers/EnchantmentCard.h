#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H
#include "AsciiGraphics.h"
#include "BaseEnchantment.h"
#include "Minion.h"
#include <iostream>

class EnchantmentCard : public Card {
    BaseEnchantment *enchantment;
    string description;
    bool affectsStats;
    string hpChange;
    string dmgChange;

    public:
    EnchantmentCard(BaseEnchantment *b, string name, int cost, string desc, string hp, string dmg);
    void applyEnchantment(Minion *m);
    card_template_t asCardTemplate();
};

#endif
