//
// Created by michalmaya on 16/06/2022.
//

#include "merchant.h"


Player& Merchant :: playCard(Player& player){
    int input = 0;
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(), player.getCoins());
    std::cin >> input;
    if (input != (valid1 || valid2|| valid3)) {
        printInvalidInput();
        std::cin >> input;
    }
    switch (input) {
        case (valid2):
            if(player.pay(healCost)){
                player.heal(heal);
            }
            else {
                printMerchantInsufficientCoins(std::cout);
            }
            printMerchantSummary(std::cout, player.getName(), heal, healCost);
        case (valid3):
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
