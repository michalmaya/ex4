//
// Created by shayr on 19/06/2022.
//

#ifndef EX4_GANG_H
#define EX4_GANG_H

#include "Battle.h"
#include "queue"

class Gang : public Battle {
public:
    Gang() ;
    ~Gang() override;
    Gang(Gang& other) = default;
    Gang& operator=(const Gang& other) = default;

    void pushMonster(Battle* &monster);

    Player& playCard(Player& player) override;
    Player& win(Player& player) override;
    Player& loss(Player& player) override;


private:
    std::queue<Battle*> m_monsterQueue;
    int m_gangSize;
    int m_aliveGangsters;
};


#endif //EX4_GANG_H
