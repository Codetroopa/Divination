#ifndef AURAOFPOWER_H
#define AURAOFPOWER_H
#include "Ritual.h"

class AuraOfPower : public Ritual {

    public:
    AuraOfPower(Player *p, string name, int cost, int ritualCost, int maxCharges, string description);
    void endOfTurnEffects(GameController *con) {};
    void startOfTurnEffects(GameController *con) {};
    void onMinionPlayEffects(GameController *con, Minion *m);
};

#endif
