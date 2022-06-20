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
    m_numOfPlayers(0),
    m_inGamePlayers(0),
    m_numOfCards(0)
{
    std::ifstream source(fileName);
    if(!source) {
        throw DeckFileNotFound();
    }

    std::map<std::string, CardsType> cardsMap;
    initializeCardsMap(cardsMap);
    std::map<std::string, Jobs> jobsMap;
    initializeJobsMap(jobsMap);

    char line[256];
    int lineCounter = 1;
    bool isGang = false;
    Card* tempCard;
    Gang* tempGang;
    while (source.getline(line,sizeof (line))) {
        auto cardsIt = cardsMap.find(line);
        bool validCard = true;
        if(cardsIt != cardsMap.end()) {
            switch (cardsIt->second) {
                case CardsType::Goblin:
                    tempCard = new Goblin();
                    break;
                case CardsType::Vampire:
                    tempCard = new Vampire();
                    break;
                case CardsType::Dragon:
                    tempCard = new Dragon();
                    break;
                case CardsType::Barfight:
                    if (isGang) {
                        validCard = false;
                        break;
                    }
                    tempCard = new Barfight();
                    break;
                case CardsType::Fairy:
                    if (isGang) {
                        validCard = false;
                        break;
                    }
                    tempCard = new Fairy();
                    break;
                case CardsType::Treasure:
                    if (isGang) {
                        validCard = false;
                        break;
                    }
                    tempCard = new Treasure();
                    break;
                case CardsType::Pitfall:
                    if (isGang) {
                        validCard = false;
                        break;
                    }
                    tempCard = new Pitfall();
                    break;
                case CardsType::Merchant:
                    if (isGang) {
                        validCard = false;
                        break;
                    }
                    tempCard = new Merchant();
                    break;
                case CardsType::Gang:
                    if (isGang) {
                        validCard = false;
                        break;
                    }
                    tempGang = new Gang();
                    isGang = true;
                    break;
                case CardsType::EndGang:
                    isGang = false;
                    tempCard = tempGang;
                    break;
            }
        }
        else
            validCard = false;

        if (!validCard)
            throw DeckFileFormatError(lineCounter);

        if (!isGang) {
            pushCard(m_deck, tempCard);
            ++m_numOfCards;
        } else
            tempGang->pushMonster((Battle *&) (tempCard));

        ++lineCounter;
    }

    if (m_numOfCards < 5)
        throw DeckFileInvalidSize();

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

    m_numOfPlayers = players;
    m_inGamePlayers = players;
    m_leadBoard = new Player*[m_numOfPlayers];
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
        if(jobIt != jobsMap.end()) {
            Player* tempPlayer;
            switch (jobIt->second) {
                case Jobs::Wizard:
                    tempPlayer = new Wizard(name.c_str());
                    m_Players.push(tempPlayer);
                    m_leadBoard[players - 1] = tempPlayer;
                    m_startingOrder[tempPlayer] = players;
                    players--;
                    break;
                case Jobs::Rogue:
                    tempPlayer = new Rogue(name.c_str());
                    m_Players.push(tempPlayer);
                    m_leadBoard[players - 1] = tempPlayer;
                    m_startingOrder[tempPlayer] = players;
                    players--;
                    break;
                case Jobs::Fighter:
                    tempPlayer = new Fighter(name.c_str());
                    m_Players.push(tempPlayer);
                    m_leadBoard[players - 1] = tempPlayer;
                    m_startingOrder[tempPlayer] = players;
                    players--;
                    break;
            }
        }
        else {
            printInvalidClass();
            continue;
        }

        if(players > 0)
            printInsertPlayerMessage();
    }

    //makeLeaderBoard();

}

void Mtmchkin::playRound() {
    m_currRound++;
    printRoundStartMessage(m_currRound);
    for (int i=0; i<m_numOfPlayers; i++){
        String curPlayerName= m_Players.front()->getName();
        printTurnStartMessage(curPlayerName);
        if(m_Players.front()->isPlayerInGame()){
            m_deck.front()->playCard(*m_Players.front());
            m_deck.push(m_deck.front());
            m_deck.pop();
        }
        m_Players.push(m_Players.front());
        m_Players.pop();
    }
    updateLeadBoard(m_leadBoard,m_inGamePlayers,m_startingOrder);
}

bool isSorted(Player** &board, int size, std::map<Player*,int> &map)
{
    for (int i = 0; i < size - 1; ++i) {
        int firstLevel = board[i]->getLevel();
        int nextLevel = board[i+1]->getLevel();
        if(nextLevel > firstLevel)
            return false;
        else if (nextLevel == firstLevel)
            if(map[board[i + 1]] <= map[board[i]])
                return false;
    }
    return true;
}

void updateLeadBoard(Player** &board, int size, std::map<Player*,int> &map)
{
    while(!isSorted(board,size,map))
    {
        for (int i = 0; i < size; ++i) {
            int firstLevel = board[i]->getLevel();
            int nextLevel = board[i+1]->getLevel();
            if(nextLevel > firstLevel)
                std::swap(board[i],board[i+1]);
            else if(nextLevel == firstLevel)
            {
                if(map[board[i + 1]] <= map[board[i]])
                    std::swap(board[i],board[i+1]);
            }
        }
    }
}


void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    for (int i=0; i<m_numOfPlayers; i++){
        printPlayerLeaderBoard(i+1, *m_leadBoard[i]);
    }
}

bool Mtmchkin::isGameOver() const {
    if(m_status == GameStatus::MidGame)
        return false;
    return true;
}

int Mtmchkin::getNumberOfRounds() const {
    return m_currRound;
}

void pushCard(std::queue<Card*>& q, Card* card)
{
    q.push(card);
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
    m["Gang"] = CardsType::Gang;
    m["EndGang"] = CardsType::EndGang;
}

void initializeJobsMap(std::map<String ,Jobs> &m) {
    m["Fighter"] = Jobs::Fighter;
    m["Rogue"] = Jobs::Rogue;
    m["Wizard"] = Jobs::Wizard;
}

bool isAllAlpha(const std::string& s)
{
    bool flag;
    for (const auto &c: s) {
        flag = std::isalpha(c);
        if(!flag)
            return false;
    }
    return true;
}

