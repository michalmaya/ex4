//
// Created by michalmaya on 17/06/2022.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Battle.h"

class Dragon : public Battle{
public:
    Dragon();
    ~Dragon() override =default;
    Dragon(Dragon& other)=default;
    Dragon& operator=(const Dragon& other)= default;
    Player& loss(Player& player) override;
};

#endif //EX4_DRAGON_H