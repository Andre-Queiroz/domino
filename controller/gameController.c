//
// Created by Caio Baracat on 23/09/20.
//

#include "gameController.h"

Game game;

void newGame() {
    Bank bank;
    game.bank = bank;

    Player *p1 = &(game.player1);
    Player *p2 = &(game.player2);

    fillPieces(&game);
    setPlayers(&game);
    drawPieces(7, &game, p1);
    drawPieces(7, &game, p2);
    gameStart(&game);
}