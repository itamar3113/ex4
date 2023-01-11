//
// Created by itama on 03/01/2023.
//

#ifndef EX4_HEALER_H
#define EX4_HEALER_H

#include "Player.h"

class Healer : public Player {
public:
    Healer(const string name);

    ~Healer() = default;

    void heal(int amount) override;

    string getJob() const override;
};

#endif //EX4_HEALER_H
