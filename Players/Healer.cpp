//
// Created by itamar on 03/01/2023.
//
#include "Healer.h"

const string JOB = "Healer";

Healer::Healer(const string name) : Player(name)
{

}

void Healer::heal(int amount) {
    Player::heal(amount * 2);
}

string Healer::getJob() const{
    return JOB;
}