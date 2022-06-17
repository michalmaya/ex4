//
// Created by michalmaya on 16/06/2022.
//

#include "Card.h"

void Card::printCard(){
    printCardDetails(std::cout, m_name);
    printEndOfCardDetails(std::cout);
}

