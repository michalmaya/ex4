//
// Created by shayr on 15/06/2022.
//

#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H

#include "Player.h"

class Rogue : public Player{
public:
    explicit Rogue(const char* name, int maxHP=100, int force=5);
    ~Rogue () override = default;
    Rogue(const Rogue& other) = default;
    Rogue& operator=(const Rogue& other) = default;

    void addCoins(int amount) override;
};


#endif //EX4_ROGUE_H
