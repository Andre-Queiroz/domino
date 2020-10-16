//
// Created by Caio Baracat on 24/09/20.
//

#include "gameView.h"

Player newPlayer()
{
    Player player;
    player.total = 0;
    //printf("Insira o nome do jogador: ");
    //scanf("%s", player.nickname);
    player.nickname[0] = 'Z';
    player.nickname[1] = 'e';

    return player;
}

void display(Piece p)
{
    printf("[%d | %d]\n", p.SideA, p.SideB);
}

void printPieces(Piece pieces[], int total)
{
    for (int i = 0; i < total; i++) {
        display(pieces[i]);
    }
}