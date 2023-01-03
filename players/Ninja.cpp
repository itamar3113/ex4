//
// Created by itama on 03/01/2023.
//
#include "Ninja.h"

const string JOB = "Ninja";

Ninja::Ninja(const string name) : Player(name) {

}

void Ninja::addCoins(int amount) {
    Player::addCoins(amount * 2);
}

string Ninja::getJob() const{
    return JOB;
}