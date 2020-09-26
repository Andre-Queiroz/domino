//
// Created by Caio Baracat on 24/09/20.
//
#include "gameView.h"

void fillPieces(Game *game) {
    int counter = 0;

    for (int x = 0; x <= 6; x++) {
        for (int z = x; z <= 6; z++) {
            Piece p = {x, z};
            game->bank.pieces[counter] = p;
            counter++;

            game->bank.total = counter;
        }
    }
}

void setPlayers(Game *game)
{
    askPlayerNickname(game->player1.nickname, 1);
    askPlayerNickname(game->player2.nickname, 2);
}