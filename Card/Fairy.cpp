//
// Created by michalmaya on 16/06/2022.
//

#include "Fairy.h"

Player& Fairy:: playCard(Player &player){
    if(player.getGob()=="Wizard"){
        player.heal(heal);
        printFairyMessage(true);
    }
    printFairyMessage(false);
    return player;
}