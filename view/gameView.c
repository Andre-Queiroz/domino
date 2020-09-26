//
// Created by Caio Baracat on 24/09/20.
//

#include "gameView.h"

void showPieces(struct Piece p) {
    printf("[ %d | %d ]\n", p.SideA, p.SideB);
}

int showMainMenu() {
    int option;

    printf("\nJOGO DE DOMINO (PUC-SP)\n\n");
    printf("[1] Iniciar novo jogo\n");
    printf("[2] Continuar a jogar\n");
    printf("[3] Salvar jogo\n");
    printf("[4] Carregar jogo\n");
    printf("[5] Regras do jogo\n");
    printf("[6] Sair do jogo\n\n");

    scanf("%d", &option);

    return option;
}

void showActionMenu() {

    printf("\nJOGO DE DOMINO (PUC-SP)\n\n");
    printf("Jogador #1,2,3,4...\n\n");
    printf("[1] Mesa do domino\n");
    printf("[2] Ver suas pecas\n");
    printf("[3] Comprar peca\n");
    printf("[4] Jogar\n");
    printf("[5] Voltar ao menu principal\n\n");
}

void askPlayerNickname(char nickname[], int playerTurn)
{
    printf("Qual o nome do jogador %d?\n", playerTurn);
    scanf("%s", nickname);
}

int play(int options)
{
    int choice = 0;
    printf("Escolha de 1 até %d\nQual peça você deseja jogar?\n", options);
    scanf("%d", &choice);

    printf("escolheu %d\n", choice);

    if (choice < 0 || choice > options) {
        printf("O número que você escolheu não é válido.\n");
        return 0;
    }

    return choice -= 1;
}

void alert(char message[])
{
    printf(message);
}