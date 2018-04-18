#ifndef RITUAL_H
#define RITUAL_H
#include "AsciiGraphics.h"
#include "Card.h"
#include "Player.h"
#include "GameController.h"
#include <vector>

class GameController;

class Ritual : public Card {
    protected:
    int ritualCost;
    int maxCharges;
    int charges;
    string description;
    Player *player;

    public:
    Ritual(Player *p, string name, int cost, int ritualCost, int maxCharges, string description);
    card_template_t asCardTemplate();
    virtual void addCharges(int amount);
    virtual void endOfTurnEffects(GameController *con) = 0;
    virtual void startOfTurnEffects(GameController *con) = 0;
    virtual void onMinionPlayEffects(GameController *con, Minion *m) = 0;
};

#endif