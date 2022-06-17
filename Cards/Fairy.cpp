//
// Created by michalmaya on 16/06/2022.
//

#include "Fairy.h"

Fairy:: Fairy(){
    Card ("Fairy", 0, 0, 0, 10);
}

Player& Fairy:: playCard(Player &player){
    if(player.getGob()=="Wizard"){
        player.heal(m_gain);
        printFairyMessage(true);
    }
    printFairyMessage(false);
    return player;
}