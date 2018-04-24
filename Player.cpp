#include "Player.h"
#include "Deck.h"
#include "Minion.h"
#include "Ritual.h"
#include "EnchantmentCard.h"
#include "Spell.h"
#include "GameController.h"
#include "BaseEnchantment.h"
#include "AbilityMinion.h"

using namespace std;

// Ctor for setting up Player and its deck
Player::Player(string name, int owner, string filePath) {
    this->hp = DEFAULT_HP;
    this->maxHp = DEFAULT_HP;
    this->magic = DEFAULT_MAGIC;
    this->maxMagic = DEFAULT_MAGIC;
    this->name = name;
    this->deck = new Deck(filePath, this);
    this->ownerNumber = owner;
    this->ritual = NULL;

    // Draw beginning cards from deck and add to hand
    for (int i = 0; i < 4; i++) {
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
bool Player::playCard(GameController *con, int i) {
    bool success = false;

    if (!validCardIndex(i)) {
        cout << "Error: You don't have a card at position " << i << endl;
        return false;
    }

    // First check if we have enough Magic to cast this card
    Card *card = hand[i - 1];
    if (card->getCost() > magic) {
        cout << "You only have " << magic << " Magic while the card costs " << card->getCost() << endl;
        return false;
    }

    Minion *m = dynamic_cast<Minion*>(hand[i - 1]);
    Ritual *r = dynamic_cast<Ritual*>(hand[i - 1]);
    Spell *s = dynamic_cast<Spell*>(hand[i - 1]);
    EnchantmentCard *e = dynamic_cast<EnchantmentCard*>(hand[i - 1]);

    // if this is true, we are playing a minion from the hand into the field
    if (m) {
        if (field.size() >= 5) {
            cout << "Your board is full!" << endl;
            return false;
        }
        addToField(m, i);
    } else if (r) {
        playRitual(r, i);
    } else if (s) {
        success = playSpell(con, s, i);
        if (success) {
            magic -= card->getCost();
        }
        return success;
    } else if (e) {
        cout << "Error: This card requires a minion to target" << endl;
        return false;
    } else {
        return false;
    }
    magic -= card->getCost();
    return true;
}

// Play a card from hand at index i targetting Minion other
bool Player::playCard(GameController *con, int i, Minion *other) {
    bool success = false;
    if (!validCardIndex(i)) {
        cout << "Error: You don't have a card at position " << i << endl;
        return false;
    }
    // First check if we have enough Magic to cast this card
    Card *card = hand[i - 1];
    if (card->getCost() > magic) {
        cout << "You don't have enough Magic!" << endl;
        return false;
    }

    EnchantmentCard *e = dynamic_cast<EnchantmentCard*>(hand[i - 1]);
    Spell *s = dynamic_cast<Spell*>(hand[i - 1]);

    if (e) {
        playEnchantment(e, other, i);
    } else if (s) {
        success = playSpell(con, s, i, other);
        if (success) {
            magic -= card->getCost();
        }
        return success;
    } else {
        cout << "This card does not require a minion to target" << endl;
        return false;
    }
    magic -= card->getCost();
    return true;
}

bool Player::useMinion(GameController *con, int i) {
    if (!validMinionIndex(i)) {
        cout << "Error: You don't have a minion at position " << i << endl;
        return false;
    }

    AbilityMinion *am = dynamic_cast<AbilityMinion*>(field[i - 1]);
    if (am) {
        if (am->attacked()) {
            cout << "The selected minion has already made a move this turn!" << endl;
            return false;
        }
        if (am->targetsMinion()) {
            cout << "This minion's ability requires a target" << endl;
            return false;
        }
        bool success = am->useAbility(con);
        if (!success) {
            cout << "This ability can't be used in the current board state!" << endl;
        }
        return success;
    } else {
        cout << "This minion does not have an ability to use!" << endl;
        return false;
    }
}

bool Player::useMinion(GameController *con, int i, Minion *other) {
    if (!validMinionIndex(i)) {
        cout << "Error: You don't have a minion at position " << i << endl;
        return false;
    }

    AbilityMinion *am = dynamic_cast<AbilityMinion*>(field[i - 1]);
    if (am) {
        if (am->attacked()) {
            cout << "The selected minion has already made a move this turn!" << endl;
            return false;
        }
        if (!am->targetsMinion()) {
            cout << "This minion's ability doesn't require a target" << endl;
            return false;
        }
        bool success = am->useAbility(con, other);
        if (!success) {
            cout << "This ability can't be used on that target!" << endl;
        }
        return success;
    } else {
        cout << "This minion does not have an ability to use!" << endl;
        return false;
    }
}

void Player::receiveDamage(int dmg) {
    hp -= dmg;
    if (hp <= 0) {
        cout << name << " has been defeated!" << endl;
        exit(0);
    }
}

void Player::restoreHealth(int amount) {
    hp = min(hp + amount, maxHp);
}

void Player::gainMagic(int amount) {
    maxMagic += amount;
    magic += amount;
}

void Player::regenerateMagic() {
    magic = maxMagic;
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

void Player::addToDeckFront(Card *c) {
    deck->addToFront(c);
}

void Player::playRitual(Ritual *r, int idx) {
    if (ritual != NULL) {
        // here it is safe to destroy the old ritual and put in the new one
        delete ritual;
    }
    ritual = r;
    hand.erase(hand.begin() + (idx - 1));
}

void Player::playEnchantment(EnchantmentCard *e, Minion *m, int idx) {
    e->applyEnchantment(m);
    hand.erase(hand.begin() + (idx - 1));
}

void Player::enchantAllFriendlyMinions(BaseEnchantment *e) {
    for (size_t i = 0; i < field.size(); i++) {
        field[i]->addEnchantment(e);
    }
}

bool Player::isFriendlyMinion(Minion *other) {
    for (size_t i = 0; i < field.size(); i++) {
        if (field[i] == other) {
            return true;
        }
    }
    return false;
}


// These are non-targetted spells
bool Player::playSpell(GameController *con, Spell *s, int idx) {
    if (s->getName() == "Recharge") {
        if (ritual) {
            ritual->addCharges(3);
        } else {
            cout << "You need to have a Ritual in play!" << endl;
            return false;
        }
    } else if (s->getName() == "Raise Dead") {
        if (graveyard.size() > 0 && field.size() < 5) {
            Minion * m = graveyard.top();
            m->revive();
            field.push_back(m);
            graveyard.pop();
        } else {
            cout << "There needs to be a Minion in the Graveyard and space on the field to play this card!" << endl;
            return false;
        }
    } else if (s->getName() == "Blizzard") {
        con->damageOpposingMinions(2);
    } else {
        cout << s->getName() << " needs to target a Minion!" << endl;
        return false;
    }
    hand.erase(hand.begin() + (idx - 1));
    return true;
}

// These are minion targetted spells
bool Player::playSpell(GameController *con, Spell *s, int idx, Minion *m) {
    if (s->getName() == "Banish") {
        m->kill();
    } else if (s->getName() == "Disenchant") {
        if (m->latestEnchantment) {
            m->removeTopEnchantment();
        } else {
            cout << "Target Minion isn't Enchanted!" << endl;
            return false;
        }
    } else if (s->getName() == "Unsummon") {
        m->resetStats();
        con->removeMinionToOwnersDeck(m);
    } else {
        cout << s->getName() << " doesn't target a Minion!" << endl;
        return false;
    }
    hand.erase(hand.begin() + (idx - 1));
    return true;
}

bool Player::validCardIndex(int i) {
    return hand.size() >= i && i <= 5 && i > 0;
}

bool Player::validMinionIndex(int i) {
    return field.size() >= i && i <= 5 && i > 0;
}

card_template_t Player::asPortrait(bool myTurn) {
    return display_player_card(ownerNumber, name, hp, magic, myTurn);
}
