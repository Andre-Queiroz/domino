//
// Created by Caio Baracat on 23/09/20.
//

#include "gameController.h"
#include "gameModel.h"
#include "gameView.h"

struct Piece bank[28];

void newGame()
{
    fillPieces(bank);

    for (int x = 0; x < 28; x++) {
        showPieces(bank[x]);
    }
}