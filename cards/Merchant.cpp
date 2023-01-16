//
// Created by itama on 07/01/2023.
//

#include "Merchant.h"
#include <limits>
const int BUY_NOTHING = 0;
const int BUY_HP = 1;
const int BUY_FORCE = 2;
const int ILLEGAL_CHOOSE = 3;

const int HP_COST = 5;
const int FORCE_COST = 10;
const int HP_BUFFER = 1;
const int FORCE_BUFFER = 1;


Merchant::Merchant() {}

void Merchant::applyEncounter(Player &player) const {
    std::ostream out_stream(std::cout.rdbuf());
    printMerchantInitialMessageForInteractiveEncounter(out_stream, player.getName(), player.getCoins());
    int choose;
    bool invalidInput = false;
    std::string inputChoose;
    while(!invalidInput)
    {
        std::getline(std::cin,inputChoose);
        try
        {
            invalidInput = true;
            choose = std::stoi(inputChoose);
            if(!(choose>=BUY_NOTHING&&choose<=BUY_FORCE))
            {
                invalidInput = false;
                printInvalidInput();
            }
        }
        catch (const std::exception& e )
        {
            printInvalidInput();
            invalidInput = false;
        }
    }
    switch(choose) {
        case BUY_NOTHING:
            printMerchantSummary(out_stream, player.getName(), BUY_NOTHING, 0);
            break;
        case BUY_HP:
            if (player.pay(HP_COST)) {
                player.heal(HP_BUFFER);
                printMerchantSummary(out_stream, player.getName(), BUY_HP, HP_COST);
            }
            else {
                printMerchantInsufficientCoins(out_stream);
                printMerchantSummary(out_stream, player.getName(), BUY_HP, 0);
            }
            break;
        case BUY_FORCE:
            if (player.pay(FORCE_COST)) {
                player.buff(FORCE_BUFFER);
                printMerchantSummary(out_stream, player.getName(), BUY_FORCE, FORCE_COST);
            }
            else {
                printMerchantInsufficientCoins(out_stream);
                printMerchantSummary(out_stream, player.getName(), BUY_FORCE, 0);
            }
            break;
    }

}
string Merchant::getName() const {
    return "Merchant";
}
