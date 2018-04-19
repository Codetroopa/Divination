#include "SilenceEnchantment.h"

SilenceEnchantment::SilenceEnchantment(BaseEnchantment *b) {
    this->prev = b;
}

bool SilenceEnchantment::isSilenced(bool flag) {
    // we don't need to go further down the decorator chain since as soon as this
    //   minion is silenced once, it can't be undone
    return true;
}
