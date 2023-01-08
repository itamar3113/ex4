//
// Created by itama on 07/01/2023.
//

#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "Card.h"

class Treasure : public Card {
public:
    Treasure();

    ~Treasure() = default;

    void applyEncounter(Player &player) const override;

    string getName() const override;
};


#endif //EX4_TREASURE_H
