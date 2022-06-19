//
// Created by michalmaya on 17/06/2022.
//

#ifndef EX4_BATTLE_H
#define EX4_BATTLE_H

#include "Card.h"

class Battle : public Card{
public:
    explicit Battle(String name="",int damage =0, int loot =0,int force =0, int gain=0);
    ~Battle() override = default;
    Battle(Battle& other)=default;
    Battle& operator=(const Battle& other)= default;
    void printCard() override;
    Player& playCard(Player& player) override;
    virtual Player& win(Player& player);
    virtual Player& loss(Player& player);
};

#endif //EX4_BATTLE_H