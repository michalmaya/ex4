//
// Created by shayr on 15/06/2022.
//

#include "Wizard.h"


Wizard::Wizard(const char *name, int order, int maxHP, int force) : Player(name,"Wizard", order, maxHP, force)
{}

void Wizard::heal(int amount) {
    Player::heal(amount * HEAL_MULTIPLIER);
}