//
// Created by itama on 05/01/2023.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"

class Barfight : public Card {
public:
    Barfight();

    ~Barfight() = default;

    void applyEncounter(Player &player) const override;

    string getName() const override;
};


#endif //EX4_BARFIGHT_H
