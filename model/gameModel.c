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

    for (int i = 0; i < total; i++) {
        srand(time(NULL));
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
    int playersHand[2], playersScore[2], higher, sum;
    bool found[2];

    for (int p = 0; p < 2; p++) {
        sum = 0;
        higher = 0;

        for (int i = 0; i < game->players[p].total; i ++) {
            if (game->players[p].hand[i].SideA == game->players[p].hand[i].SideB) {
                sum = game->players[p].hand[i].SideA + game->players[p].hand[i].SideB;

                if (sum > higher) {
                    higher = sum;
                    playersHand[p] = i;
                    playersScore[p] = higher;
                    found[p] = true;
                }
            }
        }
    }

    if (found[0] == false && found[1] == false) {
        for (int p = 0; p < 2; p++) {
            sum = 0;
            higher = 0;

            for (int i = 0; i < game->players[p].total; i ++) {
                sum = game->players[p].hand[i].SideA + game->players[p].hand[i].SideB;

                if (sum > higher) {
                    higher = sum;
                    playersHand[p] = i;
                    playersScore[p] = higher;
                }
            }
        }
    }

    if (playersScore[0] > playersScore[1]) {
        turn(game, 0, playersHand[0]);
        return 0;
    }

    turn (game, 1, playersHand[1]);
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
        handPosition = chooseAPiece(game, player);
    }

    for (int x = 0; x < game->players[player].total; x++) {
        if (x == handPosition) {
            Piece piece = game->players[player].hand[handPosition];
            display(piece);
            printf("\n");

            if (game->board.total == 0) {
                int total = game->board.total;
                game->board.pieces[total] = piece;
                game->board.total ++;

                movePlayerHand(game, player, handPosition);
                game->players[player].total--;

                break;
            }

            Piece firstPieceFromBoard = game->board.pieces[0];
            Piece lastPieceFromBoard = game->board.pieces[game->board.total-1];

            if (!isChosenPieceValid(piece, firstPieceFromBoard, lastPieceFromBoard)) {
                alert("Esta peça não cabe na mesa. Você perdeu a vez.\n");
                return;
            }

            switchSides(&piece, firstPieceFromBoard, lastPieceFromBoard);

            movePlayerHand(game, player, handPosition);
            game->players[player].total--;

            if (piece.SideB == firstPieceFromBoard.SideA) {
                printf("Lado B igual ao lado A da primeira\n");
                moveBoardPieces(game, 0);
                game->board.pieces[0] = piece;
                game->board.total ++;
            } else if(piece.SideA == lastPieceFromBoard.SideB) {
                printf("Lado A igual ao lado B da ultima\n");
                int total = game->board.total;
                game->board.pieces[total] = piece;
                game->board.total ++;
            }
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

void moveBoardPieces(Game *game, int from)
{
    for (int i = game->board.total - 1; i >= from; i--) {
        game->board.pieces[i + 1] = game->board.pieces[i];
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
            case 4:
                saveGame(game);
                printf("Jogo salvo! Encerrando.");
                exit(0);
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

    if ((chosenPiece.SideA == lastPiece.SideB) || (chosenPiece.SideB == lastPiece.SideB)) {
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

Game loadLastGame()
{
    Game game;
    FILE * file;

    file = fopen("../saves/save.bin", "rb");

    if (file == NULL) {
        return game;
    }

    fread(&game, sizeof(game), 1, file);

    return  game;
}

void saveGame(Game * game)
{
    FILE * file;
    file = fopen("../saves/save.bin", "wb");

    fwrite(game, sizeof(*game), 1, file);
}