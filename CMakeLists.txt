cmake_minimum_required(VERSION 3.24)
project(ex2_YuvalCarmeli_IdanLifshitz)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex2_YuvalCarmeli_IdanLifshitz
        Card.cpp
        Card.h
        Mtmchkin.cpp
        Mtmchkin.h
        Player.cpp
        Player.h
        test.cpp
        utilities.cpp
        utilities.h fileTester.cpp)
