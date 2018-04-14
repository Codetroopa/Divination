#ifndef COLOSSALSTRENGTH_H
#define COLOSSALSTRENGTH_H
#include "AsciiGraphics.h"
#include "BaseEnchantment.h"

class ColossalStrength : public BaseEnchantment{

    public:
    ColossalStrength(BaseEnchantment *prev);
    int getAttack(int baseDmg);
    int getHp(int baseHp);
};

#endif
