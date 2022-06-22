#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include "string"
#include "queue"
#include "map"
#include "fstream"
#include "stack"

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
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Gang.h"

#include "Exception.h"
#include "utilities.h"


enum class GameStatus{Over, MidGame};
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


    void setWinLose();

    ~Mtmchkin();


private:
    std::queue<Player*> m_Players;
    std::queue<Card*> m_deck;
    GameStatus m_status;
    int m_currRound;
    int m_numOfCards;
    int m_numOfPlayers;
    int m_winners;
    int m_inGamePlayers;
    Player** m_leadBoard;
};

void initializeCardsMap(std::map<String, CardsType>& m);

void initializeJobsMap(std::map<String, Jobs>& m);

bool isValidInput(const std::string& s);

void pushCard(std::queue<Card*> &q, Card* card);

bool isSorted(Player** &board, int start, int end);

void updateLeadBoard(Player** &board, int start, int end);

int findInLeaderBoard(Player** &board, Player& player, int start, int end);


#endif /* MTMCHKIN_H_ */
