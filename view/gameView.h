//
// Created by Caio Baracat on 24/09/20.
//

#ifndef DOMINO_GAMEVIEW_H
#define DOMINO_GAMEVIEW_H

#endif //DOMINO_GAMEVIEW_H

#include "gameModel.h"
#include "stdio.h"
#include "stdbool.h"
#include "string.h"

int showMainMenu();

void showPieces(struct Piece p);

void showActionMenu();

void alert(char message[]);

void askPlayerNickname(char nickname[], int playerTurn);

void showPLayers(struct Player players[]);

int play(int options);