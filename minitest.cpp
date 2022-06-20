#include "Mtmchkin.h"

int main()
{
    const int MAX = 100;
    Mtmchkin game("deck.txt");
    while(!game.isGameOver() && game.getNumberOfRounds() < MAX)
        game.playRound();
    game.printLeaderBoard();
    return 0;
}