//
// Created by michalmaya on 16/06/2022.
//

#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

#endif //EX4_PITFALL_H

#include "Card.h"

class Pitfall : public Card{
public:
    const static int damage= 10;
    Pitfall()=default;
    ~Pitfall()=default;
    Pitfall(Pitfall& other)=default;
    Pitfall& operator=(Pitfall& other)= default;
    Player& playCard(Player& player) override;
};
