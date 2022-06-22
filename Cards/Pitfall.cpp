//
// Created by michalmaya on 16/06/2022.
//

#include "Pitfall.h"

Pitfall::Pitfall() : Card("Pitfall", 10)
{}

Player& Pitfall:: playCard(Player& player){
    if (player.getJob() != "Rogue"){
        player.damage(getDamage());
        printPitfallMessage(false);
    }
    else
        printPitfallMessage(true);
    return player;
}