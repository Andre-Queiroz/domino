//
// Created by Caio Baracat on 24/09/20.
//

#ifndef DOMINO_GAMEVIEW_H
#define DOMINO_GAMEVIEW_H

#endif //DOMINO_GAMEVIEW_H

#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "gameModel.h"


Player newPlayer();

int showMainMenu();

void showPieces(struct Piece p, int position);

void showActionMenu();

void alert(char message[]);

void askPlayerNickname(char nickname[], int playerTurn);

void showPLayers(struct Player players[]);

int play(int options);

void showRules();