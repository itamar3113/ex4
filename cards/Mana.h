//
// Created by itama on 04/01/2023.
//

#ifndef EX4_MANA_H
#define EX4_MANA_H


#include "Card.h"

class Mana : public Card {
public:
    Mana();

    ~Mana() = default;

    void applyEncounter(Player &player) const override;

    string getName() const override;
};


#endif //EX4_MANA_H
