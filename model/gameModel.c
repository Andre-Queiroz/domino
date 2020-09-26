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
            game->bank.pieces[counter] = p;
            counter++;

            game->bank.total = counter;
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
    } while (gameEnded == false);
}

void turn(Player player)
{

    alert(strcat(player.nickname, " é a sua vez\n"));

    for (int i = 0; i < 7; ++i) {
        showPieces(player.hand[i]);
    }

    int choice = play(6);

    if (choice == 0) {
        printf("PERDEU A VEZ, OTARIO!\n");
        return;
    }


}

void drawPieces(int quantity, Game *game, Player *player)
{
    if (player -> total > 21){
        return;
    }
    for (int i = 0; i < quantity; i++) {

        int access;
        int historyPosition;

        do {
            access = randomAccess(0, 27);
            historyPosition = sweepingArray(access, game -> bank.history);
        } while (historyPosition > 0);

            player -> hand[player -> total] = game -> bank.pieces[access];
            player -> total += 1;
            game -> bank.total--;
            game -> bank.history[historyPosition + 1] = access;
    }

}


int sweepingArray(int number, int history[])
{
    for (int i = 0; i < 27; i++) {
        if (history[i] == number){
            return i;
        }
    }
    return 0;
}

int randomAccess(int min, int max)
{
    srand(time(0));
    return (rand() % (max - min + 1)) + min;
}

