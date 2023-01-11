//
// Created by itama on 04/01/2023.
//

#include "Witch.h"

const string NAME = "Witch";
const int FORCE = 12;
const int DAMAGE = 10;
const int COINS = 3;

Witch::Witch() : BattleCard(FORCE, DAMAGE, COINS) {}

string Witch::getName() const {
    return NAME;
}
