#include "../Mtmchkin.h"

int main()
{
    const int MAX = 100;
    try {
        Mtmchkin game("test288.deck");
        while (!game.isGameOver() && game.getNumberOfRounds() < MAX) {
            game.playRound();
            game.printLeaderBoard();
        }
    }
    catch ( std::exception &e)
    {
        printf("%s\n", e.what());
    }
    return 0;
}