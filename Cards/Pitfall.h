//
// Created by michalmaya on 16/06/2022.
//

#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

#include "Card.h"

class Pitfall : public Card{
public:
    Pitfall();
    ~Pitfall() override =default;
    Pitfall(Pitfall& other)=default;
    Pitfall& operator=(const Pitfall& other)= default;
    Player& playCard(Player& player) override;
};

#endif //EX4_PITFALL_H