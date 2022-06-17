//
// Created by michalmaya on 16/06/2022.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"

class Barfight : public Card{
public:
    Barfight();
    ~Barfight() override =default;
    Barfight(Barfight& other)=default;
    Barfight& operator=(const Barfight& other)= default;
    Player& playCard(Player& player) override;
};

#endif //EX4_BARFIGHT_H