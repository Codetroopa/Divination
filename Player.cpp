#include "Player.h"
#include "Deck.h"
#include "Minion.h"
using namespace std;

// Ctor for setting up Player and its deck
Player::Player(string name, int owner, string filePath) {
    this->hp = DEFAULT_HP;
    this->maxHp = DEFAULT_HP;
    this->magic = DEFAULT_MAGIC;
    this->name = name;
    this->deck = new Deck(filePath, this);
    this->ownerNumber = owner;

    // Draw beginning cards from deck and add to hand
    for (int i = 0; i < 5; i++) {
        drawCard();
    }
}

// Draw a card from this Player's deck and add it to our hand
void Player::drawCard() {
    if (hand.size() >= 5) {
        // do nothing
        cout << "Your hand is full!" << endl;
        return;
    }
    if (!deck->hasCards()) {
        cout << "You are out of cards!" << endl;
        return;
    }
    Card *drawnCard = deck->drawCard();
    if (drawnCard != NULL) {
        hand.push_back(drawnCard);
    }
}

// Play a card from hand at index i.
bool Player::playCard(int i) {
    if (!validCardIndex(i)) {
        cout << "Error: You don't have a card at position " << i << endl;
        return false;
    }
    if (field.size() >= 5) {
        cout << "Your board is full!" << endl;
        return false;
    }

    Minion *m = dynamic_cast<Minion*>(hand[i - 1]);

    // if this is true, we are playing a minion from the hand into the field
    if (m) {
        addToField(m, i);
    }
    return true;
}

// Play a card from hand at index i. Target Player p's jth minion
bool Player::playCard(int i, int p, int j) {
    return false;
}

void Player::receiveDamage(int dmg) {
    hp -= dmg;
    if (hp <= 0) {
        cout << name << " has been defeated!" << endl;
        exit(0);
    }
}

void Player::gainMagic(int amount) {
    magic += amount;
}

void Player::addToField(Minion *m, int handPosition) {
    if (field.size() > 5) {
        cout << "Error: Your board is too full to play a minion!" << endl;
        return;
    }

    // Safe to add minion to field and delete from hand
    field.push_back(m);
    hand.erase(hand.begin() + (handPosition - 1));
}

bool Player::validCardIndex(int i) {
    return hand.size() >= i && i <= 5 && i > 0;
}

card_template_t Player::asPortrait() {
    return display_player_card(ownerNumber, name, hp, magic);
}
