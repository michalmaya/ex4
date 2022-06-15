//
// Created by shayr on 15/06/2022.
//

#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H

#include "Player.h"

#define HEAL_MULTIPLIER 2


class Wizard : public Player{
public:
    explicit Wizard(const char* name, int maxHP=100, int force=5);
    ~Wizard () override = default;
    Wizard(const Wizard& other) = default;
    Wizard& operator=(const Wizard& other) = default;
    void heal(int amount) override;

};


#endif //EX4_WIZARD_H
