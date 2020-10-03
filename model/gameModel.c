//
// Created by Caio Baracat on 24/09/20.
//
#include "gameView.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void fill(Game *game)
{
    int counter = 0;
    for (int i = 0; i <= 6; i++) {
        for (int j = 0; j <= 6; j++) {
            Piece piece = {i, j};
            game->board.pieces[counter] = piece;
            counter++;
            game->board.total = counter;
        }
    }
}

void setPlayers(Game *game)
{
    for (int i = 0; i < 2; i++) {
        Player player = newPlayer();
        game->players[i] = player;
    }

    for (int i = 0; i < quantity; i++) {

        int access;
        int historyPosition;

        do {
            access = randomAccess(0, 27);
            printf("acessando peça da posição %d", access);
            historyPosition = sweepingArray(access, game->bench.history);
        } while (historyPosition > 0);

            player -> hand[player->total] = game->bench.pieces[access];
            player -> total += 1;
            game->bench.total--;
            game->bench.history[historyPosition + 1] = access;
    }

}

int sweepingArray(int number, int history[])
{
    for (int i = 0; i < 27; i++) {
        if (history[i] == number){
            printf("número %d já inserido\n", i);
            return i;
        }
    }

    printf("numero não usado\n");
    return 0;
}

int randomAccess(int min, int max)
{
    srand(time(0));
    return (rand() % (max - min + 1)) + min;
}

void removeFromHand(Player *player, int choice)
{
    for (int i = choice; i < player->total - 1; i++) {
        player->hand[i] = player->hand[i + 1];
    }

    player->total -= 1;
}

void placePiece()
{
    // verificar se a peça pode ser jogada
    // caso puder, inserir na ponta que que couber
    // Adicionar no array de peças jogadas
    // printar na tela
}
