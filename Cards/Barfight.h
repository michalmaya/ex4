//
// Created by michalmaya on 16/06/2022.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#endif //EX4_BARFIGHT_H

#include "Card.h"

class Barfight : public Card{
public:
    const static int damge= 10;
    Barfight()=default;
    ~Barfight()=default;
    Barfight(Barfight& other)=default;
    Barfight& operator=(Barfight& other)= default;
    Player& playCard(Player& player) override;

};