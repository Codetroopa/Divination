#include "Board.h"
#include "AsciiGraphics.h"
using namespace std;

// Draws the board based off of both Player's cards
void Board::draw() {
    for(card_template_t::iterator it = CENTRE_GRAPHIC.begin(); it < CENTRE_GRAPHIC.end(); it++){
        cout << *it << endl;
    }
}
