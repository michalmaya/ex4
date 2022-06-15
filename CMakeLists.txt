cmake_minimum_required(VERSION 3.22)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex4
        Mtmchkin.h
        minitests.cpp
        utilities.cpp
        utilities.h
        Exception.h
        Players/Wizard.cpp
        Players/Wizard.h
        Players/Player.cpp
        Players/Player.h Players/Fighter.cpp Players/Fighter.h Players/Rogue.cpp Players/Rogue.h minitests.cpp)
