//
// Created by Caio Baracat on 24/09/20.
//
#include "gameView.h"


void fill(Game *game)
{
    int counter = 0;
    for (int i = 0; i <= 6; i++) {
        for (int j = i; j <= 6; j++) {
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

    //printf("Antes do loop: [%d e %d]\n", game->players[0].total, game->players[1].total);
    for (int i = 0; i < total; i++) {
        do {
            access = rand() % 27;
        } while (isPieceUsed(game, access) == true);

        Piece p = game->board.pieces[access];

        int playerTotalInHand = game->players[player].total;
        game->players[player].hand[playerTotalInHand] = p;
        game->players[player].total += 1;

        //printf("Dentro do loop: [%d e %d]\n", game->players[player].total, game->players[player].total);
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

int firstPlayer(Game *game)
{
    int playerSideA, playerSideB, boardSideA, boardSideB, piecePosition;
    int piecePlayerOne = -1;
    int piecePlayerTwo = -1;

    printf("Iniciando comparação por peças iguais\n");

    for (int p = 0; p <= 1; p++) {
        printf("Jogador %d\n", p+1);

        for (int i = 0; i < game->players[p].total; i++) {
            playerSideA = game->players[p].hand[i].SideA;
            playerSideB = game->players[p].hand[i].SideB;

            printf("Peça [%d|%d]\n", playerSideA, playerSideB);
            for (int j = 6; j >= 0; j--) {
                if ((playerSideA == j) && (playerSideB == j)) {
                    piecePosition = i;

                    if (p == 1) {
                        piecePlayerTwo = j;
                    } else {
                        piecePlayerOne = j;
                    }
                }
            }
        }
    }

    if (piecePlayerOne > piecePlayerTwo) {
        turn(game, 0, piecePosition);
        return 2;
    } else if (piecePlayerTwo > piecePlayerOne) {
        turn(game, 1, piecePosition);
        return 1;
    }


    for (int x = game->board.total - 1; x >= 0; x--) {
        boardSideA = game->board.pieces[x].SideA;
        boardSideB = game->board.pieces[x].SideB;

        printf("Comparando a peça: [%d|%d]\n", boardSideA, boardSideB);

        for (int p = 0; p < 1; p++) {
            printf("Mão do jogador %d\n", p+1);
            for (int h = 0; h < game->players[p].total; h++) {
                playerSideA = game->players[p].hand[h].SideA;
                playerSideB = game->players[p].hand[h].SideB;

                if (playerSideA == playerSideB) {
                    continue;
                }

                printf("peça [%d|%d]\n", playerSideA, playerSideB);
                if (playerSideA == boardSideA && playerSideB == boardSideB) {
                    turn(game, p, h);

                    if (p == 1) {
                        return 2;
                    }

                    return 1;
                }
            }
        }
    }
}

void startGame(Game *game)
{
    bool endGame = false;
    int turn = firstPlayer(game);
    printf("turn %d", turn);

    printf("Player 1\n");
    printHand(game->players[0]);
    printf("Player 2\n");
    printHand(game->players[1]);
    exit(765);

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

void turn(Game *game, int player, int handPosition)
{
    for (int x = 0; x < game->players[player].total; x++) {
        if (x == handPosition) {
            Piece piece = game->players[player].hand[handPosition];
            moveArray(game, player, handPosition);
            game->players[player].total--;

            int total = game->board.total;
            game->board.pieces[total] = piece;
            game->board.total ++;

        }
    }
}

void moveArray(Game *game, int player, int from)
{
    int total = game->players[player].total;

    for (int i = from; i < total - 1; i++) {
        game->players[player].hand[i] = game->players[player].hand[i + 1];
    }
}

bool play(Game *game)
{
    return true;
}
