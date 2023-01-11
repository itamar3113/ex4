//
// Created by itamar on 03/01/2023.
//

#include "Player.h"

class Warrior : public Player {
public:
    explicit Warrior(const string name);

    ~Warrior() = default;

    int getAttackStrength() const override;

    string getJob() const override;
};