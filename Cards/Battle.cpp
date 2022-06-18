//
// Created by michalmaya on 17/06/2022.
//

#include "Battle.h"

Battle:: Battle(String name,int damage, int loot,int force, int gain) : Card(name, damage, loot, force, gain)
{};


void Battle::printCard(){
    bool isDragon= false;
    if (getName() == "Dragon"){
        isDragon= true;
    }
    printCardDetails(std::cout, getName());
    printMonsterDetails(std::cout, getForce(), getDamage(), getLoot(), isDragon);
    printEndOfCardDetails(std::cout);
}

Player& Battle:: playCard(Player& player){
    if (getForce() < player.getAttackStrength()){
        return win(player);
    }
    else{
        return loss(player);
    }
}

Player& Battle:: win(Player& player){
    player.buff(getGains());
    player.addCoins(getLoot());
    return player;
}

Player& Battle:: loss(Player& player){
    player.damage(getDamage());
    return player;
}