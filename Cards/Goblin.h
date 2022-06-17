//
// Created by michalmaya on 17/06/2022.
//

#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H

#endif //EX4_GOBLIN_H

#include "Card.h"
#include "Battle.h"

class Goblin : public Battle{
public:
    Goblin();
    ~Goblin()= default;
    Goblin(Goblin& other)= default;
    Goblin& operator=(Goblin& other)= default;
};
