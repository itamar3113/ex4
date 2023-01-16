//
// Created by itama on 07/01/2023.
//

#include "Merchant.h"

const int BUY_NOTHING = 0;
const int BUY_HP = 1;
const int BUY_FORCE = 2;
const int HP_COST = 5;
const int FORCE_COST = 10;
const int HP_BUFFER = 1;
const int FORCE_BUFFER = 1;


Merchant::Merchant() {}


void Merchant::applyEncounter(Player &player) const {
    std::ostream out_stream(std::cout.rdbuf());
    printMerchantInitialMessageForInteractiveEncounter(out_stream, player.getName(), player.getCoins());
    string choose;
    bool validChoose = false;
    while(!validChoose) {
        std::cin >> choose;
        if (choose == to_string(BUY_NOTHING)) {
            printMerchantSummary(out_stream, player.getName(), BUY_NOTHING, 0);
            validChoose = true;
        }
        else if (choose == to_string(BUY_HP)) {
            if (player.pay(HP_COST)) {
                player.heal(HP_BUFFER);
                printMerchantSummary(out_stream, player.getName(), BUY_HP, HP_COST);
            }
            else {
                printMerchantInsufficientCoins(out_stream);
                printMerchantSummary(out_stream, player.getName(), BUY_HP, 0);
            }
            validChoose = true;
        }
        else if (choose == to_string(BUY_FORCE)) {
            if (player.pay(FORCE_COST)) {
                player.buff(FORCE_BUFFER);
                printMerchantSummary(out_stream, player.getName(), BUY_FORCE, FORCE_COST);
            }
            else {
                printMerchantInsufficientCoins(out_stream);
                printMerchantSummary(out_stream, player.getName(), BUY_FORCE, 0);
            }
            validChoose = true;
        }
        else {
            printInvalidInput();
        }

    }
}
string Merchant::getName() const {
    return "Merchant";
}
