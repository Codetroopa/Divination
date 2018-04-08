#include "GameController.h"
#include "AsciiGraphics.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    string player1;
    string player2;

    // display banner
    cout << "Welcome to..." << endl;
    for(card_template_t::iterator it = CENTRE_GRAPHIC.begin(); it < CENTRE_GRAPHIC.end(); it++){
        cout << *it << endl;
    }

    cout << "Enter Player 1's name:" << endl;
    cin >> player1;
    cout << "Enter Player 2's name:" << endl;
    cin >> player2;
    cout << "Using default decks..." << endl << endl;


    GameController con(player1, player2, "default.deck", "default.deck");
    con.play();
}
