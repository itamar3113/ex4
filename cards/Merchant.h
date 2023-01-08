//
// Created by itama on 07/01/2023.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"

class Merchant : public Card {
public:
    Merchant();

    ~Merchant() = default;

    void applyEncounter(Player &player) const override;

    string getName() const override;
};


#endif //EX4_MERCHANT_H
