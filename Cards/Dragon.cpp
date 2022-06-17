//
// Created by michalmaya on 17/06/2022.
//

#include "Dragon.h"
//String name="",int damage =0, int loot =0,int force =0, int gain=0

Dragon::Dragon() {
    Battle("Dragon", 0, 1000, 25, 1);
}

Player& Dragon:: loss(Player& player){
    player.damage(player.getHP());
    printLossBattle(player.getName(), m_name);
    return player;
}