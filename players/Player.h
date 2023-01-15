#ifndef EX2_Player_H
#define EX2_Player_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class Player {
private:
    //todo check about copy and destructor && limit name length to 15.
    string m_name;
    int m_coins;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;

public:
    /*
    Creator of Player class.
    The player start in m_level 1, with 0 m_coins, and the initial m_HP is m_maxHP.
    If it gets illegal values, the player will get the default values(m_force = 5, m_maxHP = 100).
    @param m_name - the m_name of tje player.
    @param m_force - the initial m_force of the player.
    @param m_maxHP - the max m_HP value of the player.
    @return an instance of player.
     */
    Player(const string name);

    /*
    A copy constructor.
    */
    Player(const Player &);

    /*
    Destructor
    */
    virtual ~Player();

    Player &operator=(const Player &other);

    int getForce() const;

    /*
    Raises the player's m_level by one.
    */
    void levelUp();

    /*
    @return - the m_level of the player
    */
    int getLevel() const;

    string getName() const;

    int getCoins() const;

    /*
    Raises the player's m_force in the amount received as an argument.
    @param amount - the amount to raise the m_force.
    */
    void buff(int amount);

    /*
   Raises the player's m_HP in the amount received as an argument, up to the m_maxHP.
   @param amount - the amount to raise the m_HP.
   */
    virtual void heal(int amount);

    /*
    Drops the player's m_HP in the amount received as an argument.
    @param amount - the amount to drop the m_HP.
    */
    void damage(int amount);

    /*
    Drops the player's m_force in the amount received as an argument.
    @param amount - the amount to drop the m_force.
    */
    void damageForce(int amount);

    /*
    @return - True if m_HP = 0,
              False otherwise.
    */
    bool isKnockedOut() const;

    /*
    Add m_coins to the player in the amount received as an argument.
    @param the amount to add to m_coins
    */
    virtual void addCoins(int amount);

    /*
    Reduce m_coins from the player in the amount received as an argument.
    @param the amount to add to m_coins
    @return - True if the player have enough m_coins,
              False otherwise.
    */
    bool pay(int amount);

    /*
    @return player's m_force + m_level
    */
    virtual int getAttackStrength() const;

    virtual string getJob() const = 0;

    friend ostream &operator<<(ostream &, const Player &);
};




#endif