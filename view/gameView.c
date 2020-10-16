//
// Created by Caio Baracat on 24/09/20.
//

#include "gameView.h"

void alert(char message[])
{
    printf("%s", message);
}

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
    printf("[%d | %d]", p.SideA, p.SideB);
}

void displayTable(Game *game)
{
    printf("\n\n");
    printf("=============\n");
    printf("MESA\n");
    printf("=============\n");
    for (int i = 0; i < game->board.total; i++) {
        display(game->board.pieces[i]);
        printf(" ");
    }

    printf("\n\n");
}

int showGameMenu()
{
    int option;

    do {
        printf("Menu de ação\n");
        printf("Escolha uma das opções desejadas indicando o número correspondente: \n");
        printf("1 - Jogar uma peça\n");
        printf("2 - Comprar uma peça\n");
        printf("3 - Passar a vez\n");
        printf("0 - Sair do jogo\n");

        scanf("%d", &option);
    } while (option < 0 || option > 3);

    return option;
}

void displayPlayersHand(Game *game, int turn, bool showPlayerTurnMessage)
{

    if (showPlayerTurnMessage == true) {
        printf("Vez do jogador %d\n", turn + 1);
    }
    for (int i = 0; i < game->players[turn].total; i++) {
        printf("%d) ", i + 1);
        display(game->players[turn].hand[i]);
        printf("   ");
    }

    printf("\n\n");
}

int chooseAPiece(Game *game, int playerTurn)
{
    int choice = -1;
    displayPlayersHand(game, playerTurn, false);

    do {
        printf("Escolha uma das peças da sua mão pelo número correspondente: \n");
        scanf("%d", &choice);
    } while (choice < 1 || choice > game->players[playerTurn].total);

    return choice - 1;
}