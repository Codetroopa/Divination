#ifndef TRIGGER_MINION_H
#define TRIGGER_MINION_H
#include "Player.h"
#include "GameController.h"
#include "Minion.h"
#include "AsciiGraphics.h"
#include <iostream>
#include <vector>

using namespace std;

class TriggerMinion : public Minion {
    string description;

    public:
    TriggerMinion(Player *p, string name, int cost, int dmg, int maxHp, string desc);
    virtual void endOfTurnEffects(GameController *con) {};
    virtual void startOfTurnEffects(GameController *con) {};
    virtual void onMinionPlayEffects(GameController *con, Minion *m) {};
    virtual void deathrattle(GameController *con) {};
    virtual void die() { Minion::die(); };

    card_template_t asCardTemplate();
};

#endif