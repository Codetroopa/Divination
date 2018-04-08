#include "Player.h"
#include "Deck.h"
using namespace std;

// Ctor for setting up Player and its deck
Player::Player(string name, string filePath) {
    this->hp = DEFAULT_HP;
    this->magic = DEFAULT_MAGIC;
    this->name = name;
    this->deck = new Deck(filePath, this);
}
