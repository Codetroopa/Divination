#include "MagicFatigueEnchantment.h"

MagicFatigueEnchantment::MagicFatigueEnchantment(BaseEnchantment *b, int amount) {
    this->prev = b;
    this->amount = amount;
}

int MagicFatigueEnchantment::getActivationCost(int baseActivation) {
    if (prev) {
        return prev->getActivationCost(baseActivation) + amount;
    }
    return baseActivation + amount;
}
