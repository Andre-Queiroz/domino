//
// Created by Caio Baracat on 24/09/20.
//

#include <stdbool.h>

#ifndef DOMINO_GAMEMODEL_H
#define DOMINO_GAMEMODEL_H

#endif //DOMINO_GAMEMODEL_H

typedef struct Piece {
    int SideA;
    int SideB;
} Piece;

typedef struct Player {
    char nickname[50];
    struct Piece hand[21];
    int total;
} Player;

typedef struct Bank {
    struct Piece pieces[28];
    int history[28];
    int total;
} Bank;

typedef struct Game {
    Player player1;
    Player player2;
    Bank bank;
    int turn;
} Game;

void fillPieces(Game *game);

void setPlayers(Game *game);

void gameStart(Game *game);

void turn(Player player);

int randomAccess(int min, int max);

void drawPieces(int quantity, Game *game, Player *player);

int sweepingArray(int number, int history[]);
