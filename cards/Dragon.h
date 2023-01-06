//
// Created by itama on 04/01/2023.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "BattleCard.h"

class Dragon : public BattleCard {
public:
    Dragon();

    ~Dragon() = default;

    string getName() const override;
};


#endif //EX4_DRAGON_H
