#include "AbilityMinion.h"

AbilityMinion::AbilityMinion(Player *p, string name, int cost, int dmg, int maxHp, int activationCost, string desc)
    : Minion::Minion(p, name, cost, dmg, maxHp), description(desc), activationCost(activationCost) { }

bool AbilityMinion::isSilenced() {
    if (!latestEnchantment) {
        return false;
    } else {
        return latestEnchantment->isSilenced(false);
    }
}

int AbilityMinion::getActivationCost() {
    int totalCost = activationCost;
    if (latestEnchantment) {
        totalCost = latestEnchantment->getActivationCost(activationCost);
    }
    return totalCost;
}

bool AbilityMinion::enoughMagic() {
    cout << "Ability cost: " << getActivationCost() << endl;
    return player->magic >= getActivationCost();
}

card_template_t AbilityMinion::asCardTemplate() {
    return display_minion_activated_ability(name, cost, calculateDamage(), hp, activationCost, description);
}
