//
// Created by shayr on 15/06/2022.
//

#include "Rogue.h"

Rogue::Rogue(const char *name, int maxHP, int force) : Player(name,"Rogue",maxHP,force)
{}

void Rogue::addCoins(int amount) {
    Player::addCoins(amount * 2);
}