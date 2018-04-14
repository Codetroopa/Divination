#ifndef GIANTSTRENGTH_H
#define GIANTSTRENGTH_H
#include "AsciiGraphics.h"
#include "BaseEnchantment.h"

class GiantStrength : public BaseEnchantment{

    public:
    GiantStrength(BaseEnchantment *prev);
    int getAttack();
    int getHp(int baseHp);
};

#endif
