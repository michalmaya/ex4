//
// Created by michalmaya on 16/06/2022.
//

#include "merchant.h"

Merchant::Merchant() :
    Card("Merchant",0,0,FORCE_AMOUNT,HEAL_AMOUNT),
    m_cost(0)
{}

Player& Merchant :: playCard(Player& player)
{
    int input = -1;
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(), player.getCoins());

    std::vector<Actions> acts = {Actions::DoNothing,Actions::BuyHeal,Actions::BuyForce};
    char line[256];
    std::cin.getline(line,sizeof (line));
    try {
        input = std::stoi(line);
    }
    catch ( ... ){}
    while (input < 0 || input >= acts.size())
    {
        printInvalidInput();
        std::cin.getline(line,sizeof (line));
        try {
            input = std::stoi(line);
        }
        catch ( ... )
        {
            continue;
        }
    }

    Actions currAction = acts[input];
    switch (currAction) {
        case Actions::DoNothing:
            m_cost = 0;
            break;
        case Actions::BuyHeal:
            m_cost = HEAL_COST;
            if(player.pay(m_cost)){
                player.heal(getGains());
            }
            else {
                printMerchantInsufficientCoins(std::cout);
            }
            break;
        case Actions::BuyForce:
            m_cost = FORCE_COST;
            if(player.pay(m_cost)){
                player.buff(getForce());
            }
            else {
                printMerchantInsufficientCoins(std::cout);
            }
            break;
    }
    printMerchantSummary(std::cout, player.getName(), input, m_cost);
    return player;
}
