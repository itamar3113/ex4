//
// Created by itama on 07/01/2023.
//

#include "Well.h"

const string NAME = "Well";
const string NINJA = "Ninja";
const int DAMAGE = 10;

Well::Well() {}

void Well::applyEncounter(Player &player) const {
    if (player.getJob() != NINJA){
        player.damage(DAMAGE);
        printWellMessage(false);
    } else{
        printWellMessage(true);
    }
}

string Well::getName() const {
    return NAME;
}
