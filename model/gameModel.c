//
// Created by Caio Baracat on 24/09/20.
//
#include "gameView.h"

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

void setPlayers(struct Player players[])
{
    // Esta variavel serve para o usuario escolher quantos jogadores irão participar
    // Ainda não implementado.
    int option = 2;

    for (int x = 0; x < option; x++) {
        struct Player player;

        askPlayerNickname(player.nickname, x+1);
        player.playerTurn = x+1;
        players[x] = player;
    }
}