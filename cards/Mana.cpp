//
// Created by itama on 04/01/2023.
//

#include "Mana.h"

const string NAME = "Mana";
const string HEALER = "Healer";
const int HEAL_POWER = 10;

Mana::Mana() {}

void Mana::applyEncounter(Player &player) const {
    if (player.getJob() == HEALER){
        player.heal(HEAL_POWER);
        printManaMessage(true);
    } else{
        printManaMessage(false);
    }
}

string Mana::getName() const {
    return NAME;
}

