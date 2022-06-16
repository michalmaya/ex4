//
// Created by michalmaya on 16/06/2022.
//

#ifndef EX4_CARD_H
#define EX4_CARD_H

#endif //EX4_CARD_
#include "Players/Player.h"
#include "utilities.h"
#include "string.h"
#include "ostream"

typedef std::string String;
typedef std::ostream ostream;

class Card{
public:
    Card()=default;
    virtual ~Card()=default;
    Card(Card& other)=default;
    Card& operator=(Card& other)= default;
    virtual void printCard();
    virtual Player& playCard(Player& player);


private:
    String m_name;
};
