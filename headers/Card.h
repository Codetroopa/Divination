#ifndef CARD_H
#define CARD_H
#include <iostream>

using namespace std;

class Card {
    protected:
    string name;
    int cost;

    public:
    virtual void remove() = 0;
};

#endif