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
    int total;
} Player;

typedef struct History {
    int total;
    int used[28];
} History;

typedef struct Board {
    int total;
    Piece pieces[28];
    History history;
} Board;

typedef struct Game {
    Board board;
    Player players[2];
} Game;

void fill(Game *game);

void setPlayers(Game *game);

void draw(Game *game, int player, int total);

bool isPieceUsed(Game *game, int position);

void play(Game *game);
