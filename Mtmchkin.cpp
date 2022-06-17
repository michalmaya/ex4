//
// Created by shayr on 17/06/2022.
//

#include "Mtmchkin.h"
#include "Exception.h"
#include "fstream"
#include "utilities.h"


using std::ifstream;
using std::endl;



Mtmchkin::Mtmchkin(const std::string fileName) :
    m_Players(std::queue<Player>()),
    m_deck(std::queue<Card>()),
    m_status(GameStatus::MidGame),
    m_currRound(0)
    {
    ifstream deckFile(fileName);
    if(!deckFile) {
        throw DeckFileNotFound();
    }

    std::map<std::string, CardsType> cardsMap;
    initializeCardsMap(cardsMap);
    std::map<std::string, Jobs> jobsMap;
    initializeJobsMap(jobsMap);

    char line[256];
    int lineCounter = 0;
    while (deckFile.getline(line,sizeof (line)))
    {
        auto cardsIt = cardsMap.find(line);
        bool validCard = true;
        switch (cardsIt->second) {
            case CardsType::Goblin:
                m_deck.push(Goblin());
                break;
            case CardsType::Vampire:
                m_deck.push(Vampire());
                break;
            case CardsType::Dragon:
                m_deck.push(Dragon());
                break;
            case CardsType::Barfight:
                m_deck.push(Barfight());
                break;
            case CardsType::Fairy:
                m_deck.push(Fairy());
                break;
            case CardsType::Treasure:
                m_deck.push(Treasure());
                break;
            case CardsType::Pitfall:
                m_deck.push(Pitfall());
                break;
            case CardsType::Merchant:
                m_deck.push(Merchant());
                break;
            default:
                validCard = false;
        }
        if(validCard)
            m_numOfCards++;
        else
            throw DeckFileFormatError(lineCounter);
        ++lineCounter;
    }
    if(lineCounter < 5)
        throw DeckFileInvalidSize();

    printStartGameMessage();
    printEnterTeamSizeMessage();

    int players = 0;

    std::cin >> players;
    while(players > 6 || players < 2 ) {
        if(std::cin.fail())
            std::cin.clear();
        printInvalidTeamSize();
        std::cin >> players;
    }

    std::string input, name, job;
    std::string alphaCheck = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    printInsertPlayerMessage();
    while(players > 0){
        std::cin >> input;

        int spacePos = input.find(' ');
        if(spacePos == input.length())
        {
            printInvalidInput();
            continue;
        }

        name = input.substr(0,spacePos);
        if(name.find_first_not_of(alphaCheck)) {
            printInvalidName();
            continue;
        }

        job = input.substr(spacePos+1,input.length()-1);
        if(job.find_first_not_of(alphaCheck))
            printInvalidClass();

        auto jobIt = jobsMap.find(job);
        switch (jobIt->second) {
            case Jobs::Wizard:
                m_Players.push(Wizard(name.c_str()));
                players--;
                break;
            case Jobs::Rogue:
                m_Players.push(Rogue(name.c_str()));
                players--;
                break;
            case Jobs::Fighter:
                m_Players.push(Fighter(name.c_str()));
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