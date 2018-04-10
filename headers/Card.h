#ifndef CARD_H
#define CARD_H
#include "AsciiGraphics.h"
#include <iostream>

using namespace std;

class Card {
    protected:
    string name;
    int cost;

    public:
    virtual void remove() = 0;
    virtual card_template_t asCardTemplate() = 0;
};

#endif