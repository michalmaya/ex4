//
// Created by michalmaya on 16/06/2022.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#endif //EX4_MERCHANT_H
#include "Card.h"

class Merchant : public Card{
public:
    const static int valid1= 0;
    const static int valid2= 1;
    const static int valid3= 2;
    const static int heal=1;
    const static int force=1;
    const static int healCost=5;
    const static int forceCost=10;
    Merchant()=default;
    ~Merchant()=default;
    Merchant(Merchant& other)=default;
    Merchant& operator=(Merchant& other)=default;
    Player& playCard(Player& player) override;
};