#include "Deck.h"
#include "EnchantmentCard.h"
#include "Spell.h"
#include "DarkRitual.h"
#include "AuraOfPower.h"
#include "Minion.h"
#include "AddStatsEnchantment.h"
#include "MultStatsEnchantment.h"
#include "Standstill.h"
#include "SilenceEnchantment.h"
#include "MagicFatigueEnchantment.h"
#include "PotionSeller.h"
#include "FireElemental.h"
#include "RoyalGuard.h"
#include "NovicePyromancer.h"
#include "ApprenticeSummoner.h"
#include "MasterSummoner.h"

void Deck::shuffle() {
    // randomly swap indices 10000 times
    int i = 0;
    int j = 0;
    Card *tmp = NULL;
    for (int r = 0; r < 9999; r++) {
        i = rand() % cards.size();
        j = rand() % cards.size();
        tmp = cards[i];
        cards[i] = cards[j];
        cards[j] = tmp;
    }
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
        } else if (cardName == "Fire Elemental") {
            cards.push_back(new FireElemental(p, cardName, 2, 2, 2,
                "Whenever an opponent's minion enters play, deal 1 damage to it"));
        } else if (cardName == "Potion Seller") {
            cards.push_back(new PotionSeller(p, cardName, 2, 1, 3,
                "At the end of your turn, all friendly minions gain +0/+1"));
        } else if (cardName == "Royal Guard") {
            cards.push_back(new RoyalGuard(p, cardName, 3, 3, 4,
                "Deathrattle: restore 4 health to your hero"));
        } else if (cardName == "Novice Pyromancer") {
            cards.push_back(new NovicePyromancer(p, cardName, 1, 0, 2, 1,
                "Deal 1 damage to target minion"));
        } else if (cardName == "Apprentice Summoner") {
            cards.push_back(new ApprenticeSummoner(p, cardName, 1, 1, 1, 1,
                "Summon a 1/1 air elemental"));
        } else if (cardName == "Master Summoner") {
            cards.push_back(new MasterSummoner(p, cardName, 3, 2, 3, 2,
                "Summon up to three 1/1 air elementals"));
        } else if (cardName == "Dark Ritual") {
            cards.push_back(new DarkRitual(p, cardName, 0, 1, 5, "At the start of your turn, gain 1 magic"));
        } else if (cardName == "Aura of Power") {
            cards.push_back(new AuraOfPower(p, cardName, 1, 1, 4, "Whenever a minion is played, it gains +1/+1"));
        } else if (cardName == "Standstill") {
            cards.push_back(new Standstill(p, cardName, 3, 2, 4, "Whenever ANY minion is played, destroy it"));
        } else if (cardName == "Giant Strength") {
            cards.push_back(new EnchantmentCard(new AddStatsEnchantment(NULL, 2, 2), cardName,
                1, "", "+2", "+2"));
        } else if (cardName == "Colossal Strength") {
            cards.push_back(new EnchantmentCard(new MultStatsEnchantment(NULL, 2, 2), cardName,
                3, "", "x2", "x2"));
        } else if (cardName == "Magic Fatigue") {
            cards.push_back(new EnchantmentCard(new MagicFatigueEnchantment(NULL, 2), cardName, 0,
                "Enchanted minion's activated abilities cost 2 more", "", ""));
        } else if (cardName == "Silence") {
            cards.push_back(new EnchantmentCard(new SilenceEnchantment(NULL), cardName, 1,
                "Enchanted minion can not use abilities", "", ""));
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
        } else {
            cout << "The fuck you doing mate. This card doesn't exist" << endl;
            exit(69);
        }
    }

    // initial shuffle
    shuffle();
}
