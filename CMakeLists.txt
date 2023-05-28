cmake_minimum_required(VERSION 3.24)
project(hw2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hw2
        Card.cpp
        Card.h
        Mtmchkin.cpp
        Mtmchkin.h
        test.cpp
        utilities.cpp
        utilities.h)
