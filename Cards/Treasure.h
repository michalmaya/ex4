//
// Created by michalmaya on 16/06/2022.
//

#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#endif //EX4_TREASURE_H

#include "Card.h"

class Treasure : public Card{
public:
    Treasure();
    ~Treasure()=default;
    Treasure(Treasure& other)=default;
    Treasure& operator=(Treasure& other)= default;
    Player& playCard(Player& player) override;
};
