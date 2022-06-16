//
// Created by michalmaya on 16/06/2022.
//

#include "Barfight.h"

Player& Barfight:: playCard(Player& player){
    if (player.getGob()!="Fighter"){
        player.damage(damge);
        printBarfightMessage(false);
    }
    printBarfightMessage(true);
    return player;
}