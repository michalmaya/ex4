//
// Created by shayr on 15/06/2022.
//

#include "Wizard.h"
#include "Fighter.h"


Wizard::Wizard(const char *name, int maxHP, int force) : Player(name,"Wizard",maxHP,force)
{}

void Wizard::heal(int amount) {
    Player::heal(amount * HEAL_MULTIPLIER);
}