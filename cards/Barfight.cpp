//
// Created by itama on 05/01/2023.
//

#include "Barfight.h"

const string NAME = "Barfight";
const string WARRIOR = "Warrior";
const int DAMAGE = 8;

Barfight::Barfight() {}

void Barfight::applyEncounter(Player &player) const {
    if (player.getJob() != WARRIOR){
        player.damage(DAMAGE);
        printBarfightMessage(false);
    } else{
        printManaMessage(true);
    }
}

string Barfight::getName() const {
    return NAME;
}
