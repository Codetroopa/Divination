#include "Board.h"
#include "AsciiGraphics.h"
using namespace std;

// Draws the board based off of both Player's cards
void Board::draw() {
    for(size_t i = 0; i < CENTRE_GRAPHIC.size(); i++){
        cout << CENTRE_GRAPHIC[i] << endl;
    }
}
