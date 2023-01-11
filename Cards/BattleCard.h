//
// Created by itama on 03/01/2023.
//

#ifndef EX4_BATTLECARD_H
#define EX4_BATTLECARD_H

#include "Card.h"

class BattleCard : public Card {
private:
    int m_force;
    int m_damage;
    int m_coins;
    bool m_isDragon;

public:
    BattleCard(int force, int m_damage,int m_coins, bool isDragon = false);

    ~BattleCard() = default;

    void applyEncounter(Player &player) const override;

    void printInfo(ostream &os) override;

};


#endif //EX4_BATTLECARD_H
