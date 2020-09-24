//
// Created by Caio Baracat on 24/09/20.
//

#include "gameModel.h"

void fillPieces(struct Piece bank[]) {
    int counter = 0;

    for (int x = 0; x <= 6; x++) {
        for (int z = x; z <= 6; z++) {
            struct Piece p;

            p.SideA = x;
            p.SideB = z;

            bank[counter] = p;

            counter++;
        }
    }
}