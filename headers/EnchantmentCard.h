#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H
#include "AsciiGraphics.h"
#include "BaseEnchantment.h"
#include "Minion.h"

class EnchantmentCard : public Card {
    BaseEnchantment *enchantment;

    public:
    EnchantmentCard(BaseEnchantment *b);
    void applyEnchantment(Minion *m);
    card_template_t asCardTemplate();
};

#endif
