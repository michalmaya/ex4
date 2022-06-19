//
// Created by shayr on 17/06/2022.
//

#include "Mtmchkin.h"
#include "Exception.h"
#include "utilities.h"

using std::endl;
using std::cerr;



Mtmchkin::Mtmchkin(const std::string fileName) :
    m_Players(std::queue<Player*>()),
    m_deck(std::queue<Card*>()),
    m_status(GameStatus::MidGame),
    m_currRound(0),
    m_numOfPlayers(0)
{
    std::ifstream source("..\\" + fileName);
    if(!source) {
        throw DeckFileNotFound();
    }

    std::map<std::string, CardsType> cardsMap;
    initializeCardsMap(cardsMap);
    std::map<std::string, Jobs> jobsMap;
    initializeJobsMap(jobsMap);

    char line[256];
    int lineCounter = 0;
    while (source.getline(line,sizeof (line)))
    {
        auto cardsIt = cardsMap.find(line);
        bool validCard = true;
        switch (cardsIt->second) {
            case CardsType::Goblin:
                m_deck.push(new Goblin());
                break;
            case CardsType::Vampire:
                m_deck.push(new Vampire());
                break;
            case CardsType::Dragon:
                m_deck.push(new Dragon());
                break;
            case CardsType::Barfight:
                m_deck.push(new Barfight());
                break;
            case CardsType::Fairy:
                m_deck.push(new Fairy());
                break;
            case CardsType::Treasure:
                m_deck.push(new Treasure());
                break;
            case CardsType::Pitfall:
                m_deck.push(new Pitfall());
                break;
            case CardsType::Merchant:
                m_deck.push(new Merchant());
                break;
            default:
                validCard = false;
        }
        if(!validCard)
            throw DeckFileFormatError(lineCounter);
        ++lineCounter;
    }

    if(lineCounter < 5)
        throw DeckFileInvalidSize();

    m_numOfCards = lineCounter;
    printStartGameMessage();
    printEnterTeamSizeMessage();

    int players = 0;

    std::cin.getline(line,sizeof (line));
    try {
        players = std::stoi(line);
    }
    catch ( ... ){}
    while(players > 6 || players < 2 ) {
        printInvalidInput();
        std::cin.getline(line,sizeof (line));
        try {
            players = std::stoi(line);
        }
        catch ( ... )
        {
            continue;
        }
    }

    m_numOfPlayers=players;
    std::string name, job;

    printInsertPlayerMessage();
    while(players > 0){
        std::cin.getline(line,sizeof (line));
        std::string input = line;
        int spacePos = input.find(' ');
        if(spacePos == -1)
        {
            printInvalidInput();
            continue;
        }

        name = input.substr(0,spacePos);
        if(!isAllAlpha(name)) {
            printInvalidName();
            continue;
        }

        job = input.substr(spacePos+1,input.length()-1);
        if(!isAllAlpha(job)) {
            printInvalidClass();
            continue;
        }

        auto jobIt = jobsMap.find(job);
        switch (jobIt->second) {
            case Jobs::Wizard:
                m_Players.push(new Wizard(name.c_str()));
                players--;
                break;
            case Jobs::Rogue:
                m_Players.push(new Rogue(name.c_str()));
                players--;
                break;
            case Jobs::Fighter:
                m_Players.push(new Fighter(name.c_str()));
                players--;
                break;
            default:
                printInvalidClass();
                continue;
        }

        if(players > 0)
            printInsertPlayerMessage();
    }
}

void initializeCardsMap(std::map<String ,CardsType> &m) {
    m["Goblin"] = CardsType::Goblin;
    m["Vampire"] = CardsType::Vampire;
    m["Dragon"] = CardsType::Dragon;
    m["Barfight"] = CardsType::Barfight;
    m["Fairy"] = CardsType::Fairy;
    m["Merchant"] = CardsType::Merchant;
    m["Pitfall"] = CardsType::Pitfall;
    m["Treasure"] = CardsType::Treasure;
}

void initializeJobsMap(std::map<String ,Jobs> &m) {
    m["Fighter"] = Jobs::Fighter;
    m["Rogue"] = Jobs::Rogue;
    m["Wizard"] = Jobs::Wizard;
}

bool isAllAlpha(const std::string& s)
{
    bool flag = true;
    for (const auto &c: s) {
        flag = std::isalpha(c);
        if(!flag)
            return false;
    }
    return true;
}


void Mtmchkin:: playRound(){
    m_currRound++;
    printRoundStartMessage(m_currRound);
    for (int i=0; i<m_numOfPlayers; i++){
        String curPlayerName= m_Players.front()->getName();
        if(m_Players.front()->isPlayerInGame()){
            m_deck.front()->playCard(*m_Players.front());
            m_deck.push(m_deck.front());
            m_deck.pop();
        }
        m_Players.push(m_Players.front());
        m_Players.pop();
    }

}