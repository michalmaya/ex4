//
// Created by michalmaya on 16/06/2022.
//

#include "Card.h"

Card::Card(String name, int damage, int loot, int force, int gain) : m_name(name), m_damage(damage),
        m_loot (loot) ,m_force(force), m_gain(gain){}


void Card::printCard(){
    printCardDetails(std::cout, m_name);
    printEndOfCardDetails(std::cout);
}

int Card::getGains() const {
    return m_gain;
}

int Card::getForce() const {
    return m_force;
}

