//
// Created by michalmaya on 17/06/2022.
//

#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#include "Battle.h"

class Vampire : public Battle{
public:
    Vampire();
    ~Vampire() override =default;
    Vampire(Vampire& other)=default;
    Vampire& operator=(const Vampire& other)= default;

    Player & loss(Player &player) override;
};
#endif //EX4_VAMPIRE_H