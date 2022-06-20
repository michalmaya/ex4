cmake_minimum_required(VERSION 3.22)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex4
        Mtmchkin.h
        Mtmchkin.cpp
        utilities.cpp
        utilities.h
        Exception.h
        Players/Wizard.cpp
        Players/Wizard.h
        Players/Player.cpp
        Players/Player.h 
        Players/Fighter.cpp 
        Players/Fighter.h 
        Players/Rogue.cpp 
        Players/Rogue.h
        Cards/Barfight.cpp
        Cards/Barfight.h
        Cards/Battle.cpp
        Cards/Battle.h
        Cards/Card.cpp
        Cards/Card.h
        Cards/Dragon.cpp
        Cards/Dragon.h
        Cards/Fairy.cpp
        Cards/Fairy.h
        Cards/Gang.cpp
        Cards/Gang.h
        Cards/Goblin.cpp
        Cards/Goblin.h
        Cards/merchant.cpp
        Cards/merchant.h
        Cards/Pitfall.cpp
        Cards/Pitfall.h
        Cards/Treasure.cpp
        Cards/Treasure.h
        Cards/Vampire.cpp
        Cards/Vampire.h Cards/Gang.cpp Cards/Gang.h
        minitest.cpp)
