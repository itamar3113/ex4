//
// Created by itama on 07/01/2023.
//

#ifndef EX4_WELL_H
#define EX4_WELL_H


#include "Card.h"

class Well : public Card {
public:
    Well();

    ~Well() = default;

    void applyEncounter(Player &player) const override;

    string getName() const override;
};


#endif //EX4_WELL_H
