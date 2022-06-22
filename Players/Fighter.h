//
// Created by shayr on 15/06/2022.
//

#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H
#include "Player.h"

class Fighter : public Player{
public:
    explicit Fighter(const char* name, int order, int maxHP=100, int force=5);
    ~Fighter () override = default;
    Fighter(const Fighter& other) = default;
    Fighter& operator=(const Fighter& other) = default;

    int getAttackStrength () const override;
};


#endif //EX4_FIGHTER_H
