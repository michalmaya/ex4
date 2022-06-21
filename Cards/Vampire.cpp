//
// Created by michalmaya on 17/06/2022.
//

#include "Vampire.h"

Vampire::Vampire() : Battle("Vampire", 10, 2, 10)
{};

Player &Vampire::loss(Player &player) {
    player.damage(getDamage());
    player.weaken(FORCE_WEAKEN);
    printLossBattle(player.getName(),getName());
    return player;
}
