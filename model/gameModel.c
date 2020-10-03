//
// Created by Caio Baracat on 24/09/20.
//
#include "gameView.h"
#include <stdlib.h>
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

void draw(Game *game, int player, int total)
{
    int access;

    for (int i = 0; i < total; i++) {
        do {
            access = rand() % 27;
        } while (isPieceUsed(game, access) == true);

        Piece p = game->board.pieces[access];
        display(p);

        int playerTotalInHand = game->players[player].total;
        game->players[player].hand[playerTotalInHand] = p;
        game->players[player].total += 1;

        game->board.history.used[game->board.history.total] = access;
        game->board.history.total += 1;
    }
}

bool isPieceUsed(Game *game, int position)
{
    for (int i = 0; i < game->board.history.total; i++) {
        if (game->board.history.used[i] == position) {
            return true;
        }
    }

    return false;
}

int firstPlayer(Game *game) {
    int piece1 = -1;
    int piece2 = -1;
    int sideA;
    int sideB;

    for (int x = 0; x < game->players[1].total; x++) {
        sideA = game->players[1].hand[x].SideA;
        sideB = game->players[1].hand[x].SideB;

        if ((sideA == sideB) && piece1 < sideA) {
            piece1 = sideA;
        }
    }

    for (int x = 0; x < game->players[2].total; x++) {
        sideA = game->players[2].hand[x].SideA; // 3
        sideB = game->players[2].hand[x].SideB; // 3

        if ((sideA == sideB) && piece2 < sideA) {
            piece2 = sideA;
        }
    }

    if (piece1 >= piece2) {
        return 1;
    }
    return 2;
}

void startGame(Game *game)
{
    bool endGame = false;
    int turn = firstPlayer(game);

    do {
        if (turn == 1) {
            //player1 joga e muda o turn para player2
            turn = 2;
        } else {
            //player2 joga e muda o turn para player1
            turn = 1;
        }
        endGame = play(game);

    } while (endGame != true);
}
