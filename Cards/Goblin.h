//
// Created by michalmaya on 17/06/2022.
//

#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H

#include "Battle.h"

class Goblin : public Battle{
public:
    Goblin();
    ~Goblin() override = default;
    Goblin(Goblin& other)= default;
    Goblin& operator=(const Goblin& other)= default;
};

#endif //EX4_GOBLIN_H