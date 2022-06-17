//
// Created by michalmaya on 16/06/2022.
//

#include "Barfight.h"

Barfight::Barfight() {
    Card("Barfight", 10);
}

Player& Barfight:: playCard(Player& player){
    if (player.getGob()!="Fighter"){
        player.damage(m_damage);
        printBarfightMessage(false);
    }
    printBarfightMessage(true);
    return player;
}