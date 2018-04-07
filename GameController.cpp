#include "GameController.h"
using namespace std;

void GameController::play() {
    string cmd;
	displayHelpMessage();

	while(cin >> cmd) {
		// placeholder variables for selecting cards in hand / on the field
		int i;
		int j;

		if (cmd == "help") {
			displayHelpMessage();
		} else if (cmd == "end") {

		} else if (cmd == "quit") {

		} else if (cmd == "draw") { // -testing only

		} else if (cmd == "discard") { // -testing only

		} else if (cmd == "attack") {

		} else if (cmd == "play") {

		} else if (cmd == "use") {

		} else if (cmd == "inspect") {

		} else if (cmd == "hand") {

		} else if (cmd == "board") {

		}
	}
	// Command interpreter loop
	// while (cin >> cmd) {
	// 	// Race selection
	// 	if (!hasSelected) {
	// 		if (cmd == "q") {
	// 			break;
	// 		}
	// 		// For DLC purposes
	// 		if (cmd == "dlc") {
	// 			// Toggles fog of war
	// 			if (Floor::dlc) {
	// 				Floor::dlc = false;
	// 				cout << "Turning off DLC" << endl;
	// 			}
	// 			else {
	// 				Floor::dlc = true;
	// 				cout << "Turning DLC on" << endl;
	// 			}
	// 		}
	// 		// If a race is selected, begin the floor
	// 		else if (cmd == "s") {
	// 			string ch = "shade";
	// 			floor = new Floor(0);
	// 			floor->initialize(ch, this, file);
	// 			floor->print();
	// 			hasSelected = true;
	// 		}
	// 		else if (cmd == "d") {
	// 			string ch = "drow";
	// 			floor = new Floor(0);
	// 			floor->initialize(ch, this, file);
	// 			floor->print();
	// 			hasSelected = true;
	// 		}
	// 		else if (cmd == "v") {
	// 			string ch = "vampire";
	// 			floor = new Floor(0);
	// 			floor->initialize(ch, this, file);
	// 			floor->print();
	// 			hasSelected = true;
	// 		}
	// 		else if (cmd == "t") {
	// 			string ch = "troll";
	// 			floor = new Floor(0);
	// 			floor->initialize(ch, this, file);
	// 			floor->print();
	// 			hasSelected = true;
	// 		}
	// 		else if (cmd == "g") {
	// 			string ch = "goblin";
	// 			floor = new Floor(0);
	// 			floor->initialize(ch, this, file);
	// 			floor->print();
	// 			hasSelected = true;
	// 		}
	// 	}
	// 	// reset
	// 	else if (cmd == "r") {
	// 		if (floor) {
	// 			delete floor;
	// 			floor = NULL;
	// 		}
	// 		hasSelected = false;
	// 		printCharOptions();
	// 		if (file) {
	// 			delete file;
	// 		}
	// 		file = new fstream(fileName.c_str());
	// 	}
	// 	// quit
	// 	else if (cmd == "q") {
	// 		break;
	// 	}
	// 	else if (floor->getAlive() == false) {}
	// 	// The normal commands that can be issued when the game has started
	// 	// Checks all directions
	// 	else if (cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we"
	// 		|| cmd == "nw" || cmd == "ne" || cmd == "sw" || cmd == "se") {
	// 		if (!floor) continue;
	// 		floor->playerMove(cmd);
	// 	}

	// 	// Use potion
	// 	else if (cmd == "u") {
	// 		cin >> cmd;
	// 		// Checks all directions
	// 		if (cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we"
	// 			|| cmd == "nw" || cmd == "ne" || cmd == "sw" || cmd == "se") {
	// 			if (!floor) continue;
	// 			floor->playerUse(cmd);
	// 		}

	// 	}
	// 	// Attack a location
	// 	else if (cmd == "a") {
	// 		cin >> cmd;
	// 		// Checks all directions
	// 		if (cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we"
	// 			|| cmd == "nw" || cmd == "ne" || cmd == "sw" || cmd == "se") {
	// 			if (!floor) continue;
	// 			floor->playerAttack(cmd);
	// 		}
	// 	}
	// }
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