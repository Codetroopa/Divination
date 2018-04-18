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
    Player *player;                     // The player this minion belongs to
    vector<Minion *>::iterator fieldLocation(vector<Minion *> &field);
    void die();

    public:
    Minion(Player *p, string name, int cost, int dmg, int maxHp);
    BaseEnchantment *latestEnchantment; // Pointer to the first enchantment of the Enchantment Decorator list
    void addEnchantment(BaseEnchantment *b);
    void removeTopEnchantment();
    void kill();
    void resetStats();
    virtual bool attack(Minion *other);
    virtual bool attack(Player *other);
    virtual void receiveDamage(int amount);
    virtual void endOfTurnEffects(GameController *con);
    virtual void startOfTurnEffects(GameController *con);
    virtual int calculateDamage();
    card_template_t asCardTemplate();
};

#endif