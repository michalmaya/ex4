//
// Created by michalmaya on 16/06/2022.
//

#include "Pitfall.h"

Player& Pitfall:: playCard(Player& player){
    if (player.getGob()!= "Rogue"){
        player.damage(damage);
        printPitfallMessage(false);
    }
    printPitfallMessage(true);
    return player;
}