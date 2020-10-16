
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

    draw(&game, 0, 7);
    draw(&game, 1, 7);

    startGame(&game);
}