//
// Created by itamar on 03/01/2023.
//
#include "Player.h"

class Ninja : public Player {
public:
    Ninja(const string name);

    ~Ninja() = default;

    void addCoins(int amount) override;

    string getJob() const override;
};
