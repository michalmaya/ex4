#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include "string"
#include "queue"
#include "map"
#include "fstream"

#include "Players/Player.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"

#include "Cards/Card.h"
#include "Cards/Vampire.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Gang.h"


enum class GameStatus{Win, Loss, MidGame};
enum class CardsType{Goblin, Vampire, Dragon, Merchant, Treasure, Pitfall, Barfight, Fairy, Gang, EndGang};
enum class Jobs{Wizard, Fighter, Rogue};

class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;


private:
    std::queue<Player*> m_Players;
    std::queue<Card*> m_deck;
    int m_currRound;
    int m_numOfCards{};
    GameStatus m_status;
};

static void initializeCardsMap(std::map<String, CardsType>& m);

static void initializeJobsMap(std::map<String, Jobs>& m);

static bool isAllAlpha(const std::string& s);

static void pushCard(std::queue<Card*> q, Card* card);


#endif /* MTMCHKIN_H_ */
