#include "Deck.h"
#include "Card.h"
#include "EnchantmentCard.h"
#include "Player.h"
#include "DarkRitual.h"
#include "AuraOfPower.h"
#include "Minion.h"
#include "GiantStrength.h"
#include "ColossalStrength.h"

// Ctor to setup deck from a filename, using default deck otherwise.
Deck::Deck(string deckFilePath, Player *p) {
    string cardName;
    fstream file(deckFilePath);

    // setup ownership
    owner = p;

    // get cards from deck name
    while (getline(file, cardName)) {
        if (cardName == "Air Elemental") {
            cards.push_back(new Minion(p, cardName, 0, 1, 1));
        } else if (cardName == "Earth Elemental") {
            cards.push_back(new Minion(p, cardName, 3, 4, 4));
        } else if (cardName == "Dark Ritual") {
            cards.push_back(new DarkRitual(p, cardName, 0, 1, 5, "At the start of your turn, gain 1 magic"));
        } else if (cardName == "Aura of Power") {
            cards.push_back(new AuraOfPower(p, cardName, 1, 1, 4, "At the start of your turn, gain 1 magic"));
        } else if (cardName == "Standstill") {

        } else if (cardName == "Giant Strength") {
            cards.push_back(new EnchantmentCard(new GiantStrength(NULL), cardName,
                1, "", "+2", "+2"));
        } else if (cardName == "Colossal Strength") {
            cards.push_back(new EnchantmentCard(new ColossalStrength(NULL), cardName,
                4, "", "x2", "x2"));
        } else if (cardName == "Earth Elemental") {

        } else if (cardName == "Earth Elemental") {

        } else if (cardName == "Earth Elemental") {

        } else if (cardName == "Earth Elemental") {

        } else if (cardName == "Earth Elemental") {

        }
    }

    // initial shuffle
    shuffle();
}

void Deck::shuffle() {
    return;
}

bool Deck::hasCards() {
    return cards.size() >= 1;
}

Card * Deck::drawCard() {
    Card *card = cards.back();
    cards.pop_back();
    return card;
}
