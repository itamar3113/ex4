//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include "../players/Player.h"
#include "../utilities.h"

/*
 *  CardType:
 *  Each card has a type:
 *  BATTLE - Battle against a monster.
 *  BUFF - Increase your player's force by 'm_force' points of CardStats.
 *  HEAL - Increase your player's HP by 'm_heal' points  of CardStats (no more than maxHP points).
 *  TREASURE - Get 'm_profit' coins of CardStats.
*/


class Card {
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
    Card();


    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player &player) const = 0;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card &) = default;

    virtual ~Card();

    Card &operator=(const Card &other) = default;

    virtual string getName() const = 0;

    friend ostream &operator<<(ostream &os, Card &card);

    virtual void printInfo(ostream &os);
};


#endif //EX2_Card_H
