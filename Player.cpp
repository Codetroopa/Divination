#include "Player.h"
#include "Deck.h"
#include "Minion.h"
using namespace std;

// Ctor for setting up Player and its deck
Player::Player(string name, int owner, string filePath) {
    this->hp = DEFAULT_HP;
    this->magic = DEFAULT_MAGIC;
    this->name = name;
    this->deck = new Deck(filePath, this);
    this->ownerNumber = owner;

    // Draw beginning cards from deck and add to hand
    for (int i = 0; i < 4; i++) {
        drawCard();
    }
}

// Draw a card from this Player's deck and add it to our hand
void Player::drawCard() {
    if (hand.size() >= 5 || !deck->hasCards()) {
        // do nothing
        cout << "Can't draw a card!" << endl;
        return;
    }
    Card *drawnCard = deck->drawCard();
    if (drawnCard != NULL) {
        hand.push_back(drawnCard);
    }
}

// Play a card from hand at index i.
void Player::playCard(int i) {
    if (!validCardIndex(i)) {
        cout << "You don't have a card at position " << i << endl;
        return;
    }

    Minion *m = dynamic_cast<Minion*>(hand[i - 1]);

    // if this is true, we are playing a minion from the hand into the field
    if (m) {
        addToField(m, i);
    }
}

// Play a card from hand at index i. Target Player p's jth minion
void Player::playCard(int i, int p, int j) {

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
    return hand.size() >= i;
}
