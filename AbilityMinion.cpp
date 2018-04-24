#include "AbilityMinion.h"

AbilityMinion::AbilityMinion(Player *p, string name, int cost, int dmg, int maxHp, int activationCost, string desc)
    : Minion::Minion(p, name, cost, dmg, maxHp), description(desc), activationCost(activationCost) { }

card_template_t AbilityMinion::asCardTemplate() {
    return display_minion_activated_ability(name, cost, calculateDamage(), hp, activationCost, description);
}
