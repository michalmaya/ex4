#include "Gang.h"

Gang::Gang() :
    Battle("Gang"),
    m_monsterQueue(std::queue<Battle*>()),
    m_gangSize(0),
    m_aliveGangsters(0)
{}

void Gang::pushMonster(Battle* &monster) {
    m_gangSize++;
    m_monsterQueue.push(monster);
}

Player &Gang::playCard(Player &player) {
    bool lost = false;
    m_aliveGangsters = m_gangSize;
    while(m_aliveGangsters > 0 && !lost)
    {
        if(m_monsterQueue.front()->getForce() <= player.getAttackStrength()) {
            win(player);
            m_monsterQueue.push(m_monsterQueue.front());
            m_monsterQueue.pop();
            --m_aliveGangsters;
        }
        else
        {
            loss(player);
            lost = true;
        }
    }

    if(!lost) {
        player.levelUp();
        printWinBattle(player.getName(),getName());
    }

    return player;
}

Player& Gang::win(Player &player) {
    player.addCoins(m_monsterQueue.front()->getLoot());
    return player;
}

Player& Gang::loss(Player &player) {
    for (int i = 0; i < m_aliveGangsters; ++i) {
        m_monsterQueue.front()->loss(player);
        m_monsterQueue.push(m_monsterQueue.front());
        m_monsterQueue.pop();
    }
    return player;
}