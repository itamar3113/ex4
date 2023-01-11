//
// Created by itama on 04/01/2023.
//

#include "Gremlin.h"

const string NAME = "Gremlin";
const int FORCE = 7;
const int DAMAGE = 10;
const int COINS = 3;

Gremlin::Gremlin() : BattleCard(FORCE, DAMAGE, COINS) {}

string Gremlin::getName() const {
    return NAME;
}


