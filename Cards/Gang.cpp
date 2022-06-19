#include "Gang.h"

Gang::Gang() :
    m_monsterQueue(std::queue<Battle*>()),
    m_gangSize(0),
    Battle("Gang")
{};

void Gang::pushMonster(Battle* &monster) {
    m_monsterQueue.push(monster);
}

Player &Gang::playCard(Player &player) {
    bool lost = false;
    while(m_gangSize > 0 && !lost)
    {
        if(m_monsterQueue.front()->getForce() < player.getAttackStrength()) {
            win(player);
            m_monsterQueue.pop();
            --m_gangSize;
        }
        else
        {
            loss(player);
            lost = true;
        }
    }

    if(!lost)
        player.levelUp();

    return player;
}

Player &Gang::win(Player &player) {
    player.addCoins(m_monsterQueue.front()->getLoot());
    return player;
}

Player &Gang::loss(Player &player) {
    for (int i = 0; i < m_gangSize; ++i) {
        m_monsterQueue.front()->loss(player);
    }
    return player;
}