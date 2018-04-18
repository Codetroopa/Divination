#ifndef MINION_H
#define MINION_H
#include "Card.h"
#include "Player.h"
#include "GameController.h"
#include "BaseEnchantment.h"
#include <iostream>
#include <vector>

using namespace std;

class GameController;

class Minion : public Card {
    protected:
    int startHp;
    int maxHp;
    int hp;
    int startDmg;
    int dmg;
    int cost;
    bool hasAttacked;
    bool dead = false;
    Player *player;                     // The player this minion belongs to
    vector<Minion *>::iterator fieldLocation(vector<Minion *> &field);
    void die();

    public:
    Minion(Player *p, string name, int cost, int dmg, int maxHp);
    BaseEnchantment *latestEnchantment; // Pointer to the first enchantment of the Enchantment Decorator list
    void addEnchantment(BaseEnchantment *b);
    void removeTopEnchantment();
    void kill();
    void revive();
    bool isDead();
    void resetStats();
    bool attack(Minion *other);
    bool attack(Player *other);
    void receiveDamage(int amount);
    void endOfTurnEffects(GameController *con);
    void startOfTurnEffects(GameController *con);
    int calculateDamage();
    card_template_t asCardTemplate();
};

#endif