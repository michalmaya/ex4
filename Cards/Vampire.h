//
// Created by michalmaya on 17/06/2022.
//

#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#endif //EX4_VAMPIRE_H
#include "Card.h"
#include "Battle.h"

class Vampire : public Battle{
public:
    Vampire();
    ~Vampire()=default;
    Vampire(Vampire& other)=default;
    Vampire& operator=(Vampire& other)= default;
};