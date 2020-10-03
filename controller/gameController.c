//
// Created by Caio Baracat on 23/09/20.
//

#include "gameController.h"

Game game;

void newGame() {
    Board board;
    board.total = 0;

    History history;
    history.total = 0;

    board.history = history;
    game.board = board;

    fill(&game);
    setPlayers(&game);

    draw(&game, 1, 7);
    draw(&game, 2, 7);

    printf("oi?\n");
    //startGame(&game);
}