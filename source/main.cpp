#include "GameController.h"
#include "AsciiGraphics.h"
#include <time.h>
#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char *argv[]) {
    // init randomnes
    srand(time(NULL));
    string player1;
    string deck1;
    string player2;
    string deck2;

    // display banner
    cout << "Welcome to..." << endl;
    for(card_template_t::iterator it = CENTRE_GRAPHIC.begin(); it < CENTRE_GRAPHIC.end(); it++){
        cout << *it << endl;
    }

    cout << "Enter Player 1's name:" << endl << ">";
    cin >> player1;
    cout << "Enter Player 1's deck path (or type default for default deck):" << endl << ">";
    cin >> deck1;
    if (deck1 == "default")
    {
        deck1 = "default.deck";
        cout << "Using default deck..." << endl << endl;
    }

    cout << "Enter Player 2's name:" << endl << ">";
    cin >> player2;
    cout << "Enter Player 2's deck path (or type default for default deck):" << endl << ">";
    cin >> deck2;
    if (deck2 == "default")
    {
        deck2 = "default.deck";
        cout << "Using default deck..." << endl << endl;
    }
    

    // testing mode
    bool testingMode = false;
    if (argc > 1) {
        if (strncmp(argv[1], "--testing", 10) == 0) {
            testingMode = true;
        }
    }

    GameController con(player1, player2, deck1, deck2, testingMode);
    con.play();
}
