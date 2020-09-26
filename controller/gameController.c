//
// Created by Caio Baracat on 23/09/20.
//

#include "gameController.h"

Game game;

void newGame() {
    Bank bank;
    game.bank = bank;

    fillPieces(&game);
    setPlayers(&game);

    gameStart(&game);
}