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
    Piece hand[21];
} Player;

typedef struct Board {
    int total;
    Piece pieces[28];
    int usedPieces[28];
} Board;

typedef struct Game {
    Board board;
    Player players[2];
    int turn;
} Game;

void fill(Game *game);

void setPlayers(Game *game);