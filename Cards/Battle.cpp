//
// Created by michalmaya on 17/06/2022.
//

#include "Battle.h"

Battle:: Battle(String name,int damage, int loot,int force, int gain){
    Card(name, damage, loot, force, gain);
}


void Battle::printCard(){
    bool isDragon= false;
    if (m_name=="Dragon"){
        isDragon= true;
    }
    printCardDetails(std::cout, m_name);
    printMonsterDetails(std::cout, m_force, m_damage, m_loot, isDragon);
    printEndOfCardDetails(std::cout);
}

