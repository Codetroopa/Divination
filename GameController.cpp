#include "GameController.h"
#include "Player.h"

// Ctor to set up the game and its Players/Decks
GameController::GameController(string p1, string p2, string d1, string d2) {
    // if the deck string is empty, we should fall back to using the default deck
    this->activePlayer = new Player(p1, 1, d1);
    this->nonActivePlayer = new Player(p1, 2, d1);
}

void GameController::nextTurn() {

}

void GameController::play() {
    string cmd;
	displayHelpMessage();

	while (cin >> cmd) {
		// placeholder variables for selecting cards in hand / on the field
		int i;
		int j;

		if (cmd == "help") {
			displayHelpMessage();
		} else if (cmd == "end") {
            nextTurn();
		} else if (cmd == "quit") {
            break;
		} else if (cmd == "draw") { // -testing only
            activePlayer->drawCard();
	    } else if (cmd == "discard") { // -testing only

		} else if (cmd == "attack") {

		} else if (cmd == "play") {
            activePlayer->playCard(1);
		} else if (cmd == "use") {

		} else if (cmd == "inspect") {

		} else if (cmd == "hand") {

		} else if (cmd == "board") {
            drawBoard();
		}
	}
}

// Draw the board in its entirety
void GameController::drawBoard() {
    vector<card_template_t> displayCards;

    // Top border
    cout << EXTERNAL_BORDER_CHAR_TOP_LEFT;
    for (int i = 0; i < 165; i++) {
        cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    }
    cout << EXTERNAL_BORDER_CHAR_TOP_RIGHT << endl;

    // Draw Player 2's minions, ritual, Player portrait, and graveyard
    displayCards.clear();
    for (int i = 0; i < 5; i++) {
        displayCards.push_back(CARD_TEMPLATE_BORDER);
    }
    displayCardTemplates(displayCards);
    displayCards.clear();
    for (int i = 0; i < 5; i++) {
        displayCards.push_back(CARD_TEMPLATE_BORDER);
    }
    displayCardTemplates(displayCards);

    // Display graphic in centre
    for(card_template_t::iterator it = CENTRE_GRAPHIC.begin(); it < CENTRE_GRAPHIC.end(); it++){
        cout << *it << endl;
    }

    // Draw Player 1's minions, ritual, Player portrait, and graveyard
    displayCards.clear();
    for (int i = 0; i < 4; i++) {
        displayCards.push_back(CARD_TEMPLATE_BORDER);
    }
    if (activePlayer->field.size() == 1) {
        displayCards.push_back((activePlayer->field.front())->asCardTemplate());
    }
    displayCardTemplates(displayCards);
    displayCards.clear();
    for (int i = 0; i < 5; i++) {
        displayCards.push_back(CARD_TEMPLATE_BORDER);
    }
    displayCardTemplates(displayCards);

    // Bottom border
    cout << EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
    for (int i = 0; i < 165; i++) {
        cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    }
    cout << EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT << endl;
}

// Given a vector of Card_Templates, draws them to stdout on the same row
void GameController::displayCardTemplates(vector<card_template_t> &cards) {
    int numCards = cards.size();
    if (cards.size() != 5) {
        cout << "Error: Need to display exactly 5 cards." << endl;
        exit(1);
    }

    // go through at most 5 cards and print them
    int numRows = cards.front().size();
    for (int i = 0; i < numRows; i++) {
        cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
        cout << cards[0][i];
        cout << cards[1][i];
        cout << cards[2][i];
        cout << cards[3][i];
        cout << cards[4][i];
        cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
        cout << endl;
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