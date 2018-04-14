#ifndef GIANTSTRENGTH_H
#define GIANTSTRENGTH_H
#include "AsciiGraphics.h"
#include "BaseEnchantment.h"

class GiantStrength : public BaseEnchantment{

    public:
    GiantStrength(BaseEnchantment *prev);
    int getAttack(int baseDmg);
    int getHp(int baseHp);
};

#endif
