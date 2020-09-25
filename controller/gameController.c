//
// Created by Caio Baracat on 23/09/20.
//

#include "gameController.h"

struct Piece bank[28];
struct Player players[2];

void newGame() {
    fillPieces(bank);
    setPlayers(players);
    showPLayers(players);
}