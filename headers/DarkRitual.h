#ifndef DARKRITUAL_H
#define DARKRITUAL_H
#include "Ritual.h"

class DarkRitual : public Ritual {

    public:
    DarkRitual(Player *p, string name, int cost, int ritualCost, int maxCharges, string description);
    void endOfTurnEffects(GameController *con) {};
    void startOfTurnEffects(GameController *con);
    void onMinionPlayEffects(GameController *con) {};
};

#endif
