//
// Created by Caio Baracat on 24/09/20.
//
#include "gameController.h"
#include "gameModel.h"
#include "gameView.h"
#include <stdio.h>

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