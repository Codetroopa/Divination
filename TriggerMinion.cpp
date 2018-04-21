#include "TriggerMinion.h"

TriggerMinion::TriggerMinion(Player *p, string name, int cost, int dmg, int maxHp, string desc)
    : Minion::Minion(p, name, cost, dmg, maxHp), description(desc) { }

card_template_t TriggerMinion::asCardTemplate() {
    return display_minion_triggered_ability(name, cost, calculateDamage(), maxHp, description);
}
