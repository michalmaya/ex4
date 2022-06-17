//
// Created by michalmaya on 16/06/2022.
//

#include "Pitfall.h"

Pitfall::Pitfall() {
    Card("PItfall", 10);
}

Player& Pitfall:: playCard(Player& player){
    if (player.getGob()!= "Rogue"){
        player.damage(m_damage);
        printPitfallMessage(false);
    }
    printPitfallMessage(true);
    return player;
}