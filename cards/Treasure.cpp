//
// Created by itama on 07/01/2023.
//

#include "Treasure.h"

const string NAME = "Treasure";
const int PRIZE = 10;

Treasure::Treasure() {}

void Treasure::applyEncounter(Player &player) const {
   player.addCoins(PRIZE);
   printTreasureMessage();
}

string Treasure::getName() const {
    return NAME;
}
