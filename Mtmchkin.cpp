//
// Created by shayr on 17/06/2022.
//

#include "Mtmchkin.h"

using std::endl;
using std::cerr;

Mtmchkin::Mtmchkin(const std::string fileName) :
    m_Players(std::queue<Player*>()),
    m_deck(std::queue<Card*>()),
    m_status(GameStatus::MidGame),
    m_currRound(0),
    m_numOfCards(0)
{
    printStartGameMessage();

    std::ifstream source(fileName);
    if(!source) {
        throw DeckFileNotFound();
    }

    std::map<std::string, CardsType> cardsMap;
    std::map<std::string, Jobs> jobsMap;
    initializeCardsMap(cardsMap);
    initializeJobsMap(jobsMap);

    char line[256];
    int lineCounter = 1;

    bool isGang = false;
    Card* tempCard;
    Gang* tempGang = new Gang();
    while (source.getline(line,sizeof (line))) {
        auto cardsIt = cardsMap.find(line);
        bool validCard = true;
        if(cardsIt != cardsMap.end()) {
            if(isGang) {
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
                    case CardsType::EndGang:
                        isGang = false;
                        tempCard = tempGang;
                        break;
                    default:
                        validCard = false;
                        break;
                }
            }
            else
            {
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
                        tempCard = new Barfight();
                        break;
                    case CardsType::Fairy:
                        tempCard = new Fairy();
                        break;
                    case CardsType::Treasure:
                        tempCard = new Treasure();
                        break;
                    case CardsType::Pitfall:
                        tempCard = new Pitfall();
                        break;
                    case CardsType::Merchant:
                        tempCard = new Merchant();
                        break;
                    case CardsType::Gang:
                        tempGang = new Gang();
                        isGang = true;
                        break;
                    case CardsType::EndGang:
                        validCard = false;
                        break;
                }
            }
        }
        else
            validCard = false;

        if (!validCard) {
            delete tempGang;
            for (int i = 0; i < m_numOfCards; ++i) {
                delete m_deck.front();
                m_deck.pop();
            }
            throw DeckFileFormatError(lineCounter);
        }

        if (!isGang) {
            pushCard(m_deck, tempCard);
            ++m_numOfCards;
        } else if(cardsIt->second != CardsType::Gang)
            tempGang->pushMonster((Battle *&) (tempCard));

        ++lineCounter;
    }
    delete tempGang;

    if (m_numOfCards < 5) {
        for (int i = 0; i < m_numOfCards; ++i) {
            delete m_deck.front();
            m_deck.pop();
        }
        throw DeckFileInvalidSize();
    }

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

    printInsertPlayerMessage();
    std::string name, job;
    Player* tempPlayer;
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
            switch (jobIt->second) {
                case Jobs::Wizard:
                    tempPlayer = new Wizard(name.c_str(),players);
                    m_Players.push(tempPlayer);
                    m_leadBoard[players - 1] = tempPlayer;
                    players--;
                    break;
                case Jobs::Rogue:
                    tempPlayer = new Rogue(name.c_str(),players);
                    m_Players.push(tempPlayer);
                    m_leadBoard[players - 1] = tempPlayer;
                    players--;
                    break;
                case Jobs::Fighter:
                    tempPlayer = new Fighter(name.c_str(),players);
                    m_Players.push(tempPlayer);
                    m_leadBoard[players - 1] = tempPlayer;
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
}

void Mtmchkin::playRound() {
    m_currRound++;
    printRoundStartMessage(m_currRound);
    for (int i=0; i<m_numOfPlayers; i++){
        String curPlayerName= m_Players.front()->getName();
        if(m_Players.front()->isPlayerInGame()){
            printTurnStartMessage(curPlayerName);
            m_deck.front()->playCard(*m_Players.front());
            if(m_Players.front()->isKnockedOut())
            {
                int temp = findInLeaderBoard(m_leadBoard,*m_Players.front(),m_inGamePlayers);
                m_leadBoard[temp] = m_leadBoard[m_inGamePlayers-1];
                m_leadBoard[m_inGamePlayers-1] = m_Players.front();
                --m_inGamePlayers;
            }
            m_deck.push(m_deck.front());
            m_deck.pop();
        }
        m_Players.push(m_Players.front());
        m_Players.pop();
    }
    setWinLose();
    updateLeadBoard(m_leadBoard,m_inGamePlayers);
}

int findInLeaderBoard(Player** &board,Player& player, int size)
{
    for (int i = 0; i < size; ++i) {
        if(board[i]->getOrder() == player.getOrder())
            return i;
    }
    return -1;
}

bool isSorted(Player** &board, int size)
{
    for (int i = 0; i < size - 1; ++i) {
        int firstLevel = board[i]->getLevel();
        int nextLevel = board[i+1]->getLevel();
        if(nextLevel > firstLevel)
            return false;
        else if (nextLevel == firstLevel) {
            if (board[i + 1]->getOrder() > board[i]->getOrder())
                return false;
        }
    }
    return true;
}

void updateLeadBoard(Player** &board, int size)
{
    while(!isSorted(board,size))
    {
        for (int i = 0; i < size - 1; ++i) {
            int firstLevel = board[i]->getLevel();
            int nextLevel = board[i+1]->getLevel();
            if(nextLevel > firstLevel)
                std::swap(board[i],board[i+1]);
            else if(nextLevel == firstLevel)
            {
                if(board[i + 1]->getOrder() > board[i]->getOrder())
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

void Mtmchkin::setWinLose(){
    bool isAllWinOrDead = true;

    for (int i = 0; i < m_numOfPlayers; ++i) {
        if(!m_Players.front()->isKnockedOut() && m_Players.front()->getLevel() < 10)
            isAllWinOrDead = false;
        m_Players.push(m_Players.front());
        m_Players.pop();
    }
    if(isAllWinOrDead) {
        m_status = GameStatus::Over;
        printGameEndMessage();
    }
}

Mtmchkin::~Mtmchkin() {
    delete[] m_leadBoard;
    for (int i = 0; i < m_numOfPlayers; ++i) {
        delete m_Players.front();
        m_Players.pop();
    }
    for (int i = 0; i < m_numOfCards; ++i) {
        delete m_deck.front();
        m_deck.pop();
    }
}

