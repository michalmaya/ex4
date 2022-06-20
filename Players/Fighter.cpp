//
// Created by shayr on 15/06/2022.
//

#include "Fighter.h"

Fighter::Fighter(const char *name, int order, int maxHP, int force) : Player(name,"Fighter", order,maxHP,force)
{}

int Fighter::getAttackStrength() const {
    int force, level;
    level = getLevel();
    force = Player::getAttackStrength() - level;
    return force*2 + level;

}