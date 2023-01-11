//
// Created by itama on 04/01/2023.
//

#include "Dragon.h"

const string NAME = "Dragon";
const int FORCE = 25;
const int DAMAGE = INT_MAX;
const int COINS = 1000;

Dragon::Dragon() : BattleCard(FORCE, DAMAGE, COINS, true) {}

string Dragon::getName() const {
    return NAME;
}


