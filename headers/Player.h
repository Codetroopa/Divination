#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <iostream>

using namespace std;

class Deck;
class Card;

class Player {
    int hp;
    int magic;
    string name;
    Deck *deck;
    vector<Card *> hand;

    public:
    Player(string name, string deck);
};

const int DEFAULT_HP = 20;
const int DEFAULT_MAGIC = 3;

#endif