#include "Deck.h"
#include "EnchantmentCard.h"
#include "Spell.h"
#include "DarkRitual.h"
#include "AuraOfPower.h"
#include "Minion.h"
#include "AddStatsEnchantment.h"
#include "MultStatsEnchantment.h"

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

void Deck::addToFront(Card *c) {
    cards.push_back(c);
}

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
            cards.push_back(new EnchantmentCard(new AddStatsEnchantment(NULL, 2, 2), cardName,
                1, "", "+2", "+2"));
        } else if (cardName == "Colossal Strength") {
            cards.push_back(new EnchantmentCard(new MultStatsEnchantment(NULL, 2, 2), cardName,
                4, "", "x2", "x2"));
        } else if (cardName == "Banish") {
            cards.push_back(new Spell(p, cardName, 3, "Destroy target minion"));
        } else if (cardName == "Unsummon") {
            cards.push_back(new Spell(p, cardName, 2, "Put target minion at the top of its owner's deck"));
        } else if (cardName == "Disenchant") {
            cards.push_back(new Spell(p, cardName, 1, "Destroy the most recent enchantment or buff on the target minion"));
        } else if (cardName == "Recharge") {
            cards.push_back(new Spell(p, cardName, 1, "Gain 3 charges to your Ritual"));
        } else if (cardName == "Raise Dead") {
            cards.push_back(new Spell(p, cardName, 2, "Resurrect the top minion in your Graveyard"));
        } else if (cardName == "Blizzard") {
            cards.push_back(new Spell(p, cardName, 3, "Deal 2 damage to all enemy minions"));
        } else if (cardName == "Earth Elemental") {

        } else if (cardName == "Earth Elemental") {

        } else if (cardName == "Earth Elemental") {

        }
    }

    // initial shuffle
    shuffle();
}
