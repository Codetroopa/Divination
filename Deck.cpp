#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "DarkRitual.h"
#include "Minion.h"

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
        } else if (cardName == "Earth Elemental") {

        } else if (cardName == "Earth Elemental") {

        } else if (cardName == "Earth Elemental") {

        } else if (cardName == "Earth Elemental") {

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
