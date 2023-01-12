//
// Created by itamar on 03/01/2023.
//
#ifndef EX4_NINJA_H
#define EX4_NINJA_H

#include "Player.h"

class Ninja : public Player {
public:
    Ninja(const string name);

    ~Ninja() = default;

    void addCoins(int amount) override;

    string getJob() const override;
};
#endif