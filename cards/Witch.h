//
// Created by itama on 04/01/2023.
//

#ifndef EX4_WITCH_H
#define EX4_WITCH_H

#include "BattleCard.h"

class Witch : public BattleCard {
public:
    Witch();

    ~Witch() override = default;

    string getName() const override;

};


#endif //EX4_WITCH_H
