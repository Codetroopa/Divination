#ifndef SILENCE_Enchantment_H
#define SILENCE_Enchantment_H
#include "AsciiGraphics.h"
#include "BaseEnchantment.h"

class SilenceEnchantment : public BaseEnchantment{
    public:
    SilenceEnchantment(BaseEnchantment *prev);
    bool isSilenced(bool flag);
};

#endif
