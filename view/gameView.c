//
// Created by Caio Baracat on 24/09/20.
//

#include "gameModel.h"
#include "gameView.h"
#include "stdio.h"

void showPieces(struct Piece p)
{
    printf("[ %d | %d ]\n", p.SideA, p.SideB);
}