//
// Created by michalmaya on 16/06/2022.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#endif //EX4_MERCHANT_H
#include "Card.h"

class Merchant : public Card{
public:
    Merchant()=default;
    ~Merchant()=default;
    Merchant(Merchant& other)=default;
    Merchant& operator=(Merchant& other)=default;
    Player& playCard(Player& player) override;
};