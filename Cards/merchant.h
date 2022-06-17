//
// Created by michalmaya on 16/06/2022.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"
#include "vector"
#include "fstream"
#include "string"

#define HEAL_COST 5
#define FORCE_COST 10
#define HEAL_AMOUNT 1
#define FORCE_AMOUNT 1

enum class Actions{DoNothing, BuyHeal, BuyForce};

class Merchant : public Card{
public:
    Merchant();
    ~Merchant() override =default;
    Merchant(Merchant& other)=default;
    Merchant& operator=(const Merchant& other)=default;
    Player& playCard(Player& player) override;
private:
    int m_cost;
};

#endif //EX4_MERCHANT_H