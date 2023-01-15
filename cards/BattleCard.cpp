//
// Created by itama on 03/01/2023.
//

#include "BattleCard.h"

BattleCard::BattleCard(int force, int damage, int coins, bool isDragon) : m_force(force),
                                                                        m_damage(damage), m_coins(coins) {}

void BattleCard::applyEncounter(Player &player) const {
    if (player.getAttackStrength() >= this->m_force) {
        player.addCoins(this->m_coins);
        printWinBattle(player.getName(), getName());
        player.levelUp();
    } else {
        player.damage(m_damage);
        if(this->getName()=="Witch")
        {
            player.damageForce(1);
        }
        printLossBattle(player.getName(), getName());
    }
}

void BattleCard::printInfo(ostream &os) {
    Card::printInfo(os);
    printMonsterDetails(os, this->m_force, this->m_damage, this->m_coins, this->m_isDragon);
}
