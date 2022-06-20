//
// Created by michalmaya on 17/06/2022.
//

#include "Battle.h"

#include <utility>

Battle:: Battle(String name,int damage, int loot,int force) : Card(std::move(name), damage, loot, force)
{};


void Battle::printCard(ostream& os) const{
    bool isDragon= false;
    if (getName() == "Dragon"){
        isDragon= true;
    }
    printCardDetails(os, getName());
    printMonsterDetails(os, getForce(), getDamage(), getLoot(), isDragon);
    printEndOfCardDetails(os);
}

Player& Battle:: playCard(Player& player){
    if (getForce() <= player.getAttackStrength()){
        return win(player);
    }
    else{
        return loss(player);
    }
}

Player& Battle:: win(Player& player){
    player.levelUp();
    player.addCoins(getLoot());
    printWinBattle(player.getName(),getName());
    return player;
}

Player& Battle:: loss(Player& player){
    player.damage(getDamage());
    printLossBattle(player.getName(),getName());
    return player;
}