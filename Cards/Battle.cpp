//
// Created by michalmaya on 17/06/2022.
//

#include "Battle.h"

Battle:: Battle(String name,int damage, int loot,int force) : Card(name, damage, loot, force)
{};


void Battle::printCard(){
    bool isDragon= false;
    if (m_name=="Dragon"){
        isDragon= true;
    }
    printCardDetails(std::cout, m_name);
    printMonsterDetails(std::cout, m_force, m_damage, m_loot, isDragon);
    printEndOfCardDetails(std::cout);
}

Player& Battle:: playCard(Player& player){
    if (m_force < player.getAttackStrength()){
        return win(player);
    }
    else{
        return loss(player);
    }
}

Player& Battle:: win(Player& player){
    player.levelUp();
    player.addCoins(m_loot);
    return player;
}

Player& Battle:: loss(Player& player){
    player.damage(m_damage);
    return player;
}