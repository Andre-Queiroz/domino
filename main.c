#include <stdio.h>
#include "gameController.h"

Game game;
int main() {

    for (int z = 0; z < 10; z++) {
        Board board;
        board.total = 0;

        History history;
        history.total = 0;

        Heap heap;
        heap.total = 0;

        game.history = history;
        game.board = board;
        game.heap = heap;


        fill(&game);

        setPlayers(&game);

        draw(&game, 0, 7);
        draw(&game, 1, 7);

        bool endGame = false;
        int turn = firstPlayer(&game);

        do {
            if (turn == 0) {
                turn = 1;
            } else {
                turn = 0;
            }

            endGame = play(&game, turn);
        } while (endGame != true);
    }

//    int option;
//
//    do {
//        option = showMainMenu();
//
//        switch (option){
//            case 1:
//                printf("Iniciando novo jogo...\n");
//                newGame();
//                break;
//            case 2:
//                printf("Continuando o ultimo jogo salvo\n");
//                continueGame();
//                break;
//            case 3:
//                showRules();
//                break;
//            case 4:
//                printf("Voce saiu do jogo.\n");
//                break;
//        }
//    } while (option != 4);
//
//    return 0;
}

