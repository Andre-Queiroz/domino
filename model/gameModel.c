//
// Created by Caio Baracat on 24/09/20.
//
#include "gameView.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void fill(Game *game)
{
    int counter = 0;
    for (int i = 0; i <= 6; i++) {
        for (int j = 0; j <= 6; j++) {
            Piece piece = {i, j};
            game->board.pieces[counter] = piece;
            counter++;
            game->board.total = counter;
        }
    }
}

void setPlayers(Game *game)
{
    for (int i = 0; i < 2; i++) {
        Player player = newPlayer();
        game->players[i] = player;
    }
}