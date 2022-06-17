//
// Created by michalmaya on 17/06/2022.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#endif //EX4_DRAGON_H

#include "Battle.h"

class Dragon : public Battle{
    Dragon();
    ~Dragon()=default;
    Dragon(Dragon& other)=default;
    Dragon& operator=(Dragon& other)= default;
    Player& loss(Player& player) override;
};

