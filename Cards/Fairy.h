//
// Created by michalmaya on 16/06/2022.
//

#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#endif //EX4_FAIRY_H

#include "Card.h"

class Fairy : public Card{
public:
    Fairy();
    ~Fairy()= default;
    Fairy(Fairy& other)=default;
    Fairy& operator=(Fairy& other)=default;
    Player & playCard(Player &player) override;
};