#include "EnchantmentCard.h"

EnchantmentCard::EnchantmentCard(BaseEnchantment *b) {
    this->enchantment = b;
}

void EnchantmentCard::applyEnchantment(Minion *m) {
    m->addEnchantment(enchantment);
}

card_template_t EnchantmentCard::asCardTemplate() {

}
