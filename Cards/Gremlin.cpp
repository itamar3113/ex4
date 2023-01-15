//
// Created by itama on 04/01/2023.
//

#include "Gremlin.h"

const string NAME = "Gremlin";
const int FORCE = 5;
const int DAMAGE = 10;
const int COINS = 2;

Gremlin::Gremlin() : BattleCard(FORCE, DAMAGE, COINS, false) {}

string Gremlin::getName() const {
    return NAME;
}


