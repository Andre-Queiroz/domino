//
// Created by Caio Baracat on 24/09/20.
//

#ifndef DOMINO_GAMEVIEW_H
#define DOMINO_GAMEVIEW_H

#endif //DOMINO_GAMEVIEW_H

#include <stdlib.h>
#include <stdbool.h>
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "gameModel.h"

Player newPlayer();

void start(Game *game);

void display(Piece p);

void printHand(Player player);