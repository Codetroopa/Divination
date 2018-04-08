#include "GameController.h"
using namespace std;

void GameController::play() {
    string cmd;
    board = new Board::Board();
	displayHelpMessage();

	while(cin >> cmd) {
		// placeholder variables for selecting cards in hand / on the field
		int i;
		int j;

		if (cmd == "help") {
			displayHelpMessage();
		} else if (cmd == "end") {

		} else if (cmd == "quit") {
            break;
		} else if (cmd == "draw") { // -testing only

	    } else if (cmd == "discard") { // -testing only

		} else if (cmd == "attack") {

		} else if (cmd == "play") {

		} else if (cmd == "use") {

		} else if (cmd == "inspect") {

		} else if (cmd == "hand") {

		} else if (cmd == "board") {
            board->draw();
		}
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