//
// Created by itama on 04/01/2023.
//

#ifndef EX4_GREMLIN_H
#define EX4_GREMLIN_H

#include "BattleCard.h"

class Gremlin : public BattleCard {
public:
    Gremlin();

    ~Gremlin() override = default;

    string getName() const override;
};


#endif //EX4_GREMLIN_H
