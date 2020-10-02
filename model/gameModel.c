//
// Created by Caio Baracat on 24/09/20.
//
#include <stdlib.h>
#include <time.h>
#include "gameView.h"
#include <stdbool.h>

void fillPieces(Game *game) {
    int counter = 0;

    for (int x = 0; x <= 6; x++) {
        for (int z = x; z <= 6; z++) {
            Piece p = {x, z};
            game->bench.pieces[counter] = p;
            counter++;

            game->bench.total = counter;
        }
    }
}

void setPlayers(Game *game)
{
    game -> player1.total = 0;
    game -> player2.total = 0;
    askPlayerNickname(game->player1.nickname, 1);
    askPlayerNickname(game->player2.nickname, 2);
}


void gameStart(Game *game)
{
    bool gameEnded = false;
    game->turn = 1;

    do {
        if (game->turn == 1) {
            turn(game->player1);
            game->turn = 2;
        } else{
            turn(game->player2);
            game->turn = 1;
        };

        printf("\e[1;1H\e[2J");
    } while (gameEnded == false);
}

void turn(Player player)
{
    alert(strcat(player.nickname, " é a sua vez\n"));

    for (int i = 0; i < 7; ++i) {
        showPieces(player.hand[i], i);
    }

    int choice = play(player.total);

    if (choice == 0) {
        printf("PERDEU A VEZ, OTARIO!\n");
        return;
    }

    if (choice == -1) {
        printf("O jogador %s desistiu. Saindo do jogo", player.nickname);
        exit(0);
    }

    placePiece(player.hand[choice]);
    removeFromHand(&player, choice);
}

void drawPieces(int quantity, Game *game, Player *player)
{
    if (player -> total > 21){
        printf("player tem mais de 21 peças\n");
        return;
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

