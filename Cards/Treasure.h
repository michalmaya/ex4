//
// Created by michalmaya on 16/06/2022.
//

#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "Card.h"

class Treasure : public Card{
public:
    Treasure();
    ~Treasure() override =default;
    Treasure(Treasure& other)=default;
    Treasure& operator=(const Treasure& other)= default;
    Player& playCard(Player& player) override;
};

#endif //EX4_TREASURE_H