//
// Created by itama on 03/01/2023.
//
#include "Warrior.h"

const string JOB = "Warrior";

Warrior::Warrior(const string name) : Player(name) {
}

int Warrior::getAttackStrength() const {
    return getForce() * 2 + getLevel();
}

string Warrior::getJob() const {
    return JOB;
}