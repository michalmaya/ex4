//
// Created by michalmaya on 16/06/2022.
//

#include "merchant.h"


Player& Merchant :: playCard(Player& player){
    int input = 0;
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(), player.getCoins());
    std::cin >> input;
    if (input != (0 | 1| 2) {
        printInvalidInput();
        std::cin >> input;
    }
    switch (input) {
        case (1):
            if(player.pay(healCost)){
                player.heal(heal);
            }
            else {
                printMerchantInsufficientCoins(std::cout);
            }
            printMerchantSummary(std::cout, player.getName(), heal, healCost);
        case (2):
            if(player.pay(forceCost)){
                player.buff(force);
            }
           else {
                printMerchantInsufficientCoins(std::cout);
           }
           printMerchantSummary(std::cout, player.getName(), force, forceCost);
    }
    return player;
}
