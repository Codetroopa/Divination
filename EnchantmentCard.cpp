#include "EnchantmentCard.h"

EnchantmentCard::EnchantmentCard(BaseEnchantment *b, string name, int cost, string desc, string hp, string dmg) {
    this->enchantment = b;
    this->cost = cost;
    this->name = name;
    this->description = desc;
    this->hpChange = hp;
    this->dmgChange = dmg;
}

void EnchantmentCard::applyEnchantment(Minion *m) {
    m->addEnchantment(enchantment);
}

card_template_t EnchantmentCard::asCardTemplate() {
    if (dmgChange == "" && hpChange == "") {
        return display_enchantment(name, cost, description);
    }
    return display_enchantment_attack_defence(name, cost, description, dmgChange, hpChange);
}
