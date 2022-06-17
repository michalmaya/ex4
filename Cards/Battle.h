//
// Created by michalmaya on 17/06/2022.
//

#ifndef EX4_BATTLE_H
#define EX4_BATTLE_H

#endif //EX4_BATTLE_H

#include "Card.h"

class Battle : public Card{
public:
    Battle(String name="",int damage =0, int loot =0,int force =0, int gain=0);
    ~Battle()=default;
    Battle(Battle& other)=default;
    Battle& operator=(Battle& other)= default;
    void printCard() override;
    Player& playCard(Player& player) override;

};
