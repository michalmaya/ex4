//
// Created by michalmaya on 16/06/2022.
//

#include "Treasure.h"

Treasure::Treasure() : Card("Treasure", 0, 0, 0, 10)
{};

Player& Treasure :: playCard(Player& player){
    player.addCoins(getGains());
    printTreasureMessage();
    return player;
}