//
// Created by michalmaya on 16/06/2022.
//

#ifndef EX4_CARD_H
#define EX4_CARD_H

#include "Players/Player.h"
#include "utilities.h"
#include "string.h"
#include "ostream"

typedef std::string String;
typedef std::ostream ostream;

class Card{
public:
    explicit Card(String name,int damage =0, int loot =0,int force =0, int gain=0);
    virtual ~Card() = default;
    Card(const Card& other)=default;
    Card& operator=(const Card& other)= default;

    virtual void printCard(ostream& os) const;
    virtual Player& playCard(Player& player) =0;

    int getGains() const;
    int getForce() const;
    int getDamage() const;
    int getLoot() const;
    String getName() const;

    friend ostream& operator<<(ostream& os, const Card& card);


private:
    String m_name;
    int m_damage;
    int m_loot;
    int m_force;
    int m_gain;
};

#endif //EX4_CARD_H