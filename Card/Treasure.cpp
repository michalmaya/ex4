//
// Created by michalmaya on 16/06/2022.
//

#include "Treasure.h"

Player& Treasure :: playCard(Player& player){
    player.addCoins(coins);
    printTreasureMessage();
    return player;
}