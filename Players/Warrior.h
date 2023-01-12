//
// Created by itamar on 03/01/2023.
//
#ifndef EX4_WARRIOR_H
#define EX4_WARRIOR_H

#include "Player.h"

class Warrior : public Player {
public:
    explicit Warrior(const string name);

    ~Warrior() = default;

    int getAttackStrength() const override;

    string getJob() const override;
};
#endif //EX4_WARRIOR_H

