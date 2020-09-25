#include <stdio.h>
#include "gameController.h"
#include "gameView.h"

int main() {
    int option;

    do {
        option = showMainMenu();

        switch (option){
            case 1:
                printf("Iniciando novo jogo...\n");
                newGame();
                break;
            case 2:
                printf("Continuando\n");
                //call the function
                break;
            case 3:
                printf("Salvando jogo...\n");
                //call the function
                break;
            case 4:
                printf("Carregando jogo...\n");
                //call the function
                break;
            case 5:
                printf("Regras do jogo:\n");
                //call the function
                break;
            case 6:
                printf("Voce saiu do jogo.\n");
                break;
        }
    } while (option != 6);
    return 0;
}

