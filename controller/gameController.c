//
// Created by Caio Baracat on 23/09/20.
//

#include "gameController.h"

Game game;

void newGame() {
    Board board;
    game.board = board;

    fill(&game);
    setPlayers(*game);
}