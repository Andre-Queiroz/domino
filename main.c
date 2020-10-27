#include <stdio.h>
#include "gameController.h"

size_t writeFile(FILE *file, Game *game);
size_t readFile(FILE *file, Game *game);

int main() {
    //int option;

    FILE *file;

    file = fopen("arquivo.bin", "wb");

    if (file == NULL) {
        printf("Nao criou o arquivo\n");
        return 0;
    }

    Game game;

    writeFile(&file, &game);
    readFile(&file, &game);
    fclose(file);

    //newGame();

//    do {
//        option = showMainMenu();
//
//        switch (option){
//            case 1:
//                printf("Iniciando novo jogo...\n");
//                newGame();
//                break;
//            case 2:
//                printf("Continuando\n");
//                //call the function
//                break;
//            case 3:
//                printf("Salvando jogo...\n");
//                //call the function
//                break;
//            case 4:
//                printf("Carregando jogo...\n");
//                //call the function
//                break;
//            case 5:
//                showRules();
//                break;
//            case 6:
//                printf("Voce saiu do jogo.\n");
//                break;
//        }
//    } while (option != 6);
    return 0;
}

size_t writeFile(FILE *file, Game *game)
{
    int content = fwrite(&game, sizeof(game), 1, file);
}

size_t readFile(FILE *file, Game *game)
{
    int content = fread(&game, sizeof(game), 1, file);
}