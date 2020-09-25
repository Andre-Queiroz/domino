cmake_minimum_required(VERSION 3.17)
project(domino C)

set(CMAKE_C_STANDARD 11)

include_directories(controller)
include_directories(model)
include_directories(view)

add_executable(domino
        controller/gameController.c
        controller/gameController.h
        model/gameModel.c
        model/gameModel.h
        view/gameView.c
        view/gameView.h
        main.c)
