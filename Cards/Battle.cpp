//
// Created by michalmaya on 17/06/2022.
//

#include "Battle.h"

void Battle::printCard(){
    bool isDragon= false;
    //if ()
    printCardDetails(std::cout, m_name);
    printMonsterDetails(std::cout, m_force, m_damage, m_loot, isDragon);
    printEndOfCardDetails(std::cout);
}