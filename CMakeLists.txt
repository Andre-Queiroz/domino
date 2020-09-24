cmake_minimum_required(VERSION 3.17)
project(Domino)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
set(CMAKE_CXX_STANDARD 14)

include_directories(controller)
include_directories(model)
include_directories(view)

add_executable(Domino
        main.c controller/gameController.c controller/gameController.h model/gameModel.c model/gameModel.h view/gameView.c view/gameView.h)
