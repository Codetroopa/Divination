#include "GameController.h"
#include "Player.h"

// Ctor to set up the game and its Players/Decks
GameController::GameController(string p1, string p2, string d1, string d2) {
    // if the deck string is empty, we should fall back to using the default deck
    this->activePlayer = new Player(p1, 1, d1);
    this->nonActivePlayer = new Player(p2, 2, d2);
    this->turn = 1;
}

void GameController::nextTurn() {
    if (turn == 1) {
        turn = 2;
    } else {
        turn = 1;
    }
    // End of turn triggers for active player
    for (size_t i = 0; i < activePlayer->field.size(); i++) {
        activePlayer->field[i]->endOfTurnEffects(this);
    }
    if (activePlayer->ritual) {
        activePlayer->ritual->endOfTurnEffects(this);
    }

    // THE ACTUAL TURN ENDING HAPPENS HERE (Active Player switches)
    Player *hold = activePlayer;
    activePlayer = nonActivePlayer;
    nonActivePlayer = hold;
    // THE ACTUAL TURN ENDING HAPPENS HERE (Active Player switches)

    // Start of turn triggers for new active player
    for (size_t i = 0; i < activePlayer->field.size(); i++) {
        activePlayer->field[i]->startOfTurnEffects(this);
    }
    if (activePlayer->ritual) {
        activePlayer->ritual->startOfTurnEffects(this);
    }

    // Now the new Active Player draws a card and gains magic before finally beginning their turn
    activePlayer->drawCard();
    activePlayer->gainMagic(1);
}

void GameController::play() {
    string cmd;
	displayHelpMessage();
    cout << ">";

	while (cin >> cmd) {
		// placeholder variables for selecting cards in hand / on the field
		int i;
		int j;
        int p;
        bool success;

		if (cmd == "help") {
			displayHelpMessage();
		} else if (cmd == "end") {
            nextTurn();
            drawBoard();
		} else if (cmd == "quit") {
            break;
		} else if (cmd == "draw") { // -testing only
            activePlayer->drawCard();
	    } else if (cmd == "discard") { // -testing only

		} else if (cmd == "attack") {
            getline(cin, cmd);
            istringstream iss(cmd);
            if (!(iss >> i)) {
                cout << "Error: Bad input: " << cmd << endl;
                cout << ">";
                continue;
            }

            if (iss.eof()) {
                success = makeAttack(i);
                if (success) {
                    drawBoard();
                }
            } else {
                if (!(iss >> j)) {
                    cout << "Error: Bad input: " << cmd << endl;
                    cout << ">";
                    continue;
                }
                success = makeAttack(i, j);
                if (success) {
                    drawBoard();
                }
            }
		} else if (cmd == "play") {
            getline(cin, cmd);
            istringstream iss(cmd);
            if (!(iss >> i)) {
                cout << "Error: Bad input: " << cmd << endl;
                cout << ">";
                continue;
            }

            if (iss.eof()) {
                success = activePlayer->playCard(i);
                if (success) {
                    drawBoard();
                }
            } else {
                if (!(iss >> p)) {
                    cout << "Error: Bad input: " << cmd << endl;
                    cout << ">";
                    continue;
                }

                if (!(iss >> j)) {
                    cout << "Error: Bad input: " << cmd << endl;
                    cout << ">";
                    continue;
                }

                Minion *other;
                if (p == activePlayer->ownerNumber) {
                    if (activePlayer->field.size() < j || j <= 0) {
                        cout << "Error: Target Minion doesn't exist at index " << j << endl;
                        cout << ">";
                        continue;
                    }
                    other = activePlayer->field[j - 1];
                } else {
                    if (nonActivePlayer->field.size() < j || j <= 0) {
                        cout << "Error: Target Minion doesn't exist at index " << j << endl;
                        cout << ">";
                        continue;
                    }
                    other = nonActivePlayer->field[j - 1];
                }
                success = activePlayer->playCard(i, other);
                if (success) {
                    drawBoard();
                }
            }
		} else if (cmd == "use") {

		} else if (cmd == "inspect") {

		} else if (cmd == "hand") {
            vector<card_template_t> cards;
            for (vector<Card *>::iterator it = activePlayer->hand.begin(); it < activePlayer->hand.end(); it++) {
                cards.push_back((*it)->asCardTemplate());
            }
            int numCards = cards.size();
            for (int i = 0; i < 5 - numCards; i++) {
                cards.push_back(CARD_TEMPLATE_EMPTY);
            }
            displayCardTemplates(cards, false);
		} else if (cmd == "board") {
            drawBoard();
		} else {
            cout << "Invalid command. Type \"help\" for a list of commands." << endl;
        }

        // prompt for the user
        cout << ">";
	}
}

// Active Player attacks Opposing Player with minion i
bool GameController::makeAttack(int i) {
    if (activePlayer->field.size() < i || i < 0 || i > 5) {
        cout << "Error: You don't have a minion at position " << i << endl;
        return false;
    }
    return activePlayer->field[i - 1]->attack(nonActivePlayer);
}

// Active Player's minion i attacks Opposing Player's minion j
bool GameController::makeAttack(int i, int j) {
    if (activePlayer->field.size() < i || i <= 0 || i > 5) {
        cout << "Error: You don't have a minion at position " << i << endl;
        return false;
    }
    if (nonActivePlayer->field.size() < j || j <= 0 || j > 5) {
        cout << "Error: There isn't an enemy minion to attack at position " << j << endl;
        return false;
    }
    return activePlayer->field[i - 1]->attack(nonActivePlayer->field[j - 1]);
}

void GameController::addMana(int amount, bool activePlayer) {
    if (activePlayer == true) {
        this->activePlayer->gainMagic(amount);
    } else {
        this->nonActivePlayer->gainMagic(amount);
    }
}


// Draw the board in its entirety
void GameController::drawBoard() {
    vector<card_template_t> displayCards;
    Player * p1;
    Player * p2;
    int numMinions;

    if (turn == 1) {
        p1 = activePlayer;
        p2 = nonActivePlayer;
    } else {
        p1 = nonActivePlayer;
        p2 = activePlayer;
    }

    // Top border
    cout << EXTERNAL_BORDER_CHAR_TOP_LEFT;
    for (int i = 0; i < 165; i++) {
        cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    }
    cout << EXTERNAL_BORDER_CHAR_TOP_RIGHT << endl;

    // Draw Player 2's ritual, Player portrait, and graveyard
    displayCards.clear();
    if (p2->ritual != NULL) {
        displayCards.push_back(p2->ritual->asCardTemplate());
    } else {
        displayCards.push_back(CARD_TEMPLATE_BORDER);
    }
    displayCards.push_back(CARD_TEMPLATE_EMPTY);
    displayCards.push_back(p2->asPortrait());
    displayCards.push_back(CARD_TEMPLATE_EMPTY);
    if (p2->graveyard.size() > 0) {
        displayCards.push_back(p2->graveyard.top()->asCardTemplate());
    } else {
        displayCards.push_back(CARD_TEMPLATE_BORDER);
    }
    displayCardTemplates(displayCards, true);

    // Draw Player 2's Minions
    displayCards.clear();
    for (vector<Minion *>::iterator it = p2->field.begin(); it < p2->field.end(); it++) {
        displayCards.push_back((*it)->asCardTemplate());
    }
    numMinions = displayCards.size();
    for (int i = 0; i < 5 - numMinions; i++) {
        displayCards.push_back(CARD_TEMPLATE_BORDER);
    }
    displayCardTemplates(displayCards, true);
    // Display graphic in centre
    for(card_template_t::iterator it = CENTRE_GRAPHIC.begin(); it < CENTRE_GRAPHIC.end(); it++){
        cout << *it << endl;
    }

    // Draw Player 1's Minions
    displayCards.clear();
    for (vector<Minion *>::iterator it = p1->field.begin(); it < p1->field.end(); it++) {
        displayCards.push_back((*it)->asCardTemplate());
    }
    numMinions = displayCards.size();
    for (int i = 0; i < 5 - numMinions; i++) {
        displayCards.push_back(CARD_TEMPLATE_BORDER);
    }
    displayCardTemplates(displayCards, true);

    // Draw Player 1's ritual, Player portrait, and graveyard
    displayCards.clear();
    if (p1->ritual != NULL) {
        displayCards.push_back(p1->ritual->asCardTemplate());
    } else {
        displayCards.push_back(CARD_TEMPLATE_BORDER);
    }
    displayCards.push_back(CARD_TEMPLATE_EMPTY);
    displayCards.push_back(p1->asPortrait());
    displayCards.push_back(CARD_TEMPLATE_EMPTY);
    if (p1->graveyard.size() > 0) {
        displayCards.push_back(p1->graveyard.top()->asCardTemplate());
    } else {
        displayCards.push_back(CARD_TEMPLATE_BORDER);
    }
    displayCardTemplates(displayCards, true);

    // Bottom border
    cout << EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
    for (int i = 0; i < 165; i++) {
        cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    }
    cout << EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT << endl;
}

// Given a vector of Card_Templates, draws them to stdout on the same row
void GameController::displayCardTemplates(vector<card_template_t> &cards, bool withBorder) {
    int numCards = cards.size();
    if (cards.size() != 5) {
        cout << "Error: Need to display exactly 5 cards. Given " << numCards << endl;
        exit(1);
    }

    // go through at most 5 cards and print them
    int numRows = cards.front().size();
    for (int i = 0; i < numRows; i++) {
        if (withBorder) {
            cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
        }
        cout << cards[0][i];
        cout << cards[1][i];
        cout << cards[2][i];
        cout << cards[3][i];
        cout << cards[4][i];
        if (withBorder) {
            cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
        }        cout << endl;
    }
}

void GameController::displayHelpMessage() {
	cout << "Commands:" << endl;
	cout << "help -- Display this message." << endl;
	cout << "end -- End the current player's turn." << endl;
	cout << "quit -- End the game." << endl;
	cout << "attack minion other-minion -- Orders minion to attack other-minion." << endl;
	cout << "attack minion -- Orders minion to attack the opponent." << endl;
	cout << "play card [player target] -- Play card, optionally targeting player's target card." << endl;
	cout << "use minion [player target] -- Use minion's special ability, optionally targeting player's target card." << endl;
	cout << "inspect minion -- View a minion's card and all enchantments on that minion." << endl;
	cout << "hand -- Describe all cards in your hand." << endl;
	cout << "board -- Describe all cards on the board." << endl;
}
