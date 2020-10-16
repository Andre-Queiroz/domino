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
            game->heap.pieces[counter] = piece;
            counter++;
            game->heap.total = counter;
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

        Piece p = game->heap.pieces[access];

        int playerTotalInHand = game->players[player].total;
        game->players[player].hand[playerTotalInHand] = p;
        game->players[player].total += 1;

        game->history.used[game->history.total] = access;
        game->history.total += 1;
    }
}

bool isPieceUsed(Game *game, int position)
{
    for (int i = 0; i < game->history.total; i++) {
        if (game->history.used[i] == position) {
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

    for (int p = 0; p <= 1; p++) {
        for (int i = 0; i < game->players[p].total; i++) {
            playerSideA = game->players[p].hand[i].SideA;
            playerSideB = game->players[p].hand[i].SideB;

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

        for (int p = 0; p < 1; p++) {
            for (int h = 0; h < game->players[p].total; h++) {
                playerSideA = game->players[p].hand[h].SideA;
                playerSideB = game->players[p].hand[h].SideB;

                if (playerSideA == playerSideB) {
                    continue;
                }

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

    return 1;
}

void startGame(Game *game)
{
    bool endGame = false;
    int turn = firstPlayer(game);

    do {
        if (turn == 0) {
            turn = 1;
        } else {
            turn = 0;
        }

        endGame = play(game, turn);
    } while (endGame != true);
}

void turn(Game *game, int player, int handPosition)
{
    if (handPosition == -1) {
        handPosition = chooseAPiece();
    }
printf("escolheu a posição %d\n", handPosition);
    for (int x = 0; x < game->players[player].total; x++) {
        if (x == handPosition) {
            Piece piece = game->players[player].hand[handPosition];

            if (game->board.total == 0) {
                printf("A mesa está vazia, populando pela primeira vez\n");
                int total = game->board.total;
                game->board.pieces[total] = piece;
                game->board.total ++;

                break;
            }

            Piece firstPieceFromBoard = game->board.pieces[0];
            Piece lastPieceFromBoard = game->board.pieces[game->board.total-1];

            printf("Primeira peça: \n");
            display(firstPieceFromBoard);
            printf("\n");
            printf("Ultima peça: \b");
            display(lastPieceFromBoard);
            printf("\n");

            if (!isChosenPieceValid(piece, firstPieceFromBoard, lastPieceFromBoard)) {
                alert("Esta peça não cabe na mesa. Você perdeu a vez.\n");
                return;
            }

            switchSides(&piece, firstPieceFromBoard, lastPieceFromBoard);

            printf("Peça trocada: \n");
            display(piece);
            printf("\n");

            movePlayerHand(game, player, handPosition);
            game->players[player].total--;

            if (piece.SideB == firstPieceFromBoard.SideA) {
                printf("Lado B igual ao lado A da primeira\n");
                moveBoardPieces(game, 0);
                game->board.pieces[0] = piece;
            } else if(piece.SideA == lastPieceFromBoard.SideB) {
                printf("Lado A igual ao lado B da ultima\n");
                int total = game->board.total;
                game->board.pieces[total] = piece;
            }

            game->board.total ++;

        }
    }
}

void movePlayerHand(Game *game, int player, int from)
{
    int total = game->players[player].total;

    for (int i = from; i < total - 1; i++) {
        game->players[player].hand[i] = game->players[player].hand[i + 1];
    }
}

void moveBoardPieces(Game *game, int from) {
    int total = game->board.total;
    Piece swap = game->board.pieces[from];

    for (int i = from; i < total; i++) {
        game->board.pieces[i + 1] = swap;
        swap = game->board.pieces[i];
    }
}

bool play(Game *game, int playerTurn)
{
    int option;
    bool drewOnce = false;
    bool turnHasFinished = false;

    displayTable(game);
    displayPlayersHand(game, playerTurn, true);

    do {
        option = showGameMenu();

        switch (option) {
            case 1:
                turn(game, playerTurn, -1);
                turnHasFinished = true;
                break;
            case 2:
                draw(game, playerTurn, 1);
                displayPlayersHand(game, playerTurn, false);
                drewOnce = true;
                break;
            case 3:
                turnHasFinished = true;

                if (drewOnce == false) {
                    alert("Você precisa jogar uma peça ou sacar uma peça ao menos uma vez. Tente novamente\n");
                    turnHasFinished = false;
                }
                break;
            case 0:
                alert("Você desistiu do jogo.\n");
                if (playerTurn == 0) {
                    playerTurn = 1;
                } else {
                    playerTurn = 0;
                }
                game->players[playerTurn].total = 0;
                turnHasFinished = true;
                break;
            default:
                alert("Ação inválida!\n");
                break;
        }
    } while (turnHasFinished == false);

    return isGameEnded(game, playerTurn);
}

bool isGameEnded(Game *game, int turn)
{
    if (game->players[turn].total == 0) {
        return true;
    }

    return false;
}

bool isChosenPieceValid(Piece chosenPiece, Piece firstPiece, Piece lastPiece)
{
    if ((chosenPiece.SideA == firstPiece.SideA) || (chosenPiece.SideB == firstPiece.SideA)) {
        return true;
    }

    if ((chosenPiece.SideA == lastPiece.SideB) || (chosenPiece.SideB == lastPiece.SideA)) {
        return true;
    }

    return false;
}

void switchSides(Piece *chosenPiece, Piece firstPiece, Piece lastPiece)
{
    int swap;
    if (chosenPiece->SideA == firstPiece.SideA) {
        swap = chosenPiece->SideB;
        chosenPiece->SideB = chosenPiece->SideA;
        chosenPiece->SideA = swap;

        return;
    }

    if (chosenPiece->SideB == lastPiece.SideB) {
        swap = chosenPiece->SideA;
        chosenPiece->SideA = chosenPiece->SideB;
        chosenPiece->SideB = swap;
    }
}