//
// Created by michalmaya on 16/06/2022.
//

#include "Fairy.h"

Fairy:: Fairy() : Card ("Fairy", 0, 0, 0, 10)
{}

Player& Fairy:: playCard(Player &player){
    if(player.getJob()=="Wizard"){
        player.heal(getGains());
        printFairyMessage(true);
    }
    else
        printFairyMessage(false);
    return player;
}