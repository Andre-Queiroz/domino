cmake_minimum_required(VERSION 3.17)
project(Domino)

set(CMAKE_CXX_STANDARD 14)

include_directories(controller)

add_executable(Domino
        main.c controller/gameController.c controller/gameController.h)
