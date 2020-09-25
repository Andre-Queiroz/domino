//
// Created by Caio Baracat on 24/09/20.
//

#ifndef DOMINO_GAMEMODEL_H
#define DOMINO_GAMEMODEL_H

#endif //DOMINO_GAMEMODEL_H

typedef struct Piece {
    int SideA;
    int SideB;
} Piece;

typedef struct Player {
    int playerTurn;
    char nickname[50];
    struct Piece hand[7];
} Player;

void fillPieces(struct Piece bank[]);

void setPlayers(struct Player players[]);