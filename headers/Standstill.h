#ifndef STANDSTILL_H
#define STANDSTILL_H
#include "Ritual.h"

class Standstill : public Ritual {

    public:
    Standstill(Player *p, string name, int cost, int ritualCost, int maxCharges, string description);
    void endOfTurnEffects(GameController *con) {};
    void startOfTurnEffects(GameController *con) {};
    void onMinionPlayEffects(GameController *con, Minion *m);
};

#endif
