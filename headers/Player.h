#ifndef PLAYER_H
#define PLAYER_H
#include "AsciiGraphics.h"
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Deck;
class Card;
class Minion;
class Ritual;
class EnchantmentCard;
class Spell;
class GameController;
class BaseEnchantment;

class Player {
    int maxHp;
    int hp;
    int maxMagic;
    int magic;
    string name;
    Deck *deck;

    // private methods
    bool validCardIndex(int i);
    void playRitual(Ritual *r, int i);
    bool playSpell(GameController *con, Spell *r, int i);
    bool playSpell(GameController *con, Spell *r, int idx, Minion *m);
    void playEnchantment(EnchantmentCard *e, Minion *m, int i);
    void addToField(Minion *m, int position);

    public:
    vector<Card *> hand;                    // This Player's cards in hand
    vector<Minion *> field;                 // This Player's minions in the field, and still alive
    stack<Minion *> graveyard;              // This Player's minions that have been killed
    Ritual *ritual;
    int ownerNumber;                        // This is either 1 or 2 for Player 1 or 2
    Player(string name, int o, string deck);
    void drawCard();
    bool playCard(GameController *con, int i);                   // Play a card from hand at index i.
    bool playCard(GameController *con, int i, Minion *other);    // Play a card from hand at index i. Target given Minion
    void receiveDamage(int dmg);
    void addToDeckFront(Card *c);
    void gainMagic(int amount);
    void regenerateMagic();
    void enchantAllFriendlyMinions(BaseEnchantment *e);
    card_template_t asPortrait();           // Display as a card_template_t
};

const int DEFAULT_HP = 20;
const int DEFAULT_MAGIC = 3;

#endif