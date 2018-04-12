#ifndef MINION_H
#define MINION_H
#include "Card.h"
#include "Player.h"
#include <iostream>
#include <vector>

using namespace std;

class Minion : public Card {
    int startHp;
    int maxHp;
    int hp;
    int startDmg;
    int dmg;
    int cost;
    Player *player;                     // The player this minion belongs to
    vector<Minion *>::iterator fieldLocation(vector<Minion *> &field);
    void die();

    public:

    Minion(Player *p, string name, int cost, int dmg, int maxHp);
    void remove();
    virtual void attack(Minion *other);
    virtual void attack(Player *other);
    virtual void receiveDamage(int amount);
    virtual int calculateDamage();
    card_template_t asCardTemplate();
};

#endif