#include "Player.h"
#include "../utilities.h"

const int DEFAULT_FORCE = 5;
const int DEFAULT_MAX_HP = 100;
const int INIT_COINS = 10;

Player::Player(const string name) : m_name(name),
                                    m_coins(INIT_COINS),
                                    m_level(1),
                                    m_force(DEFAULT_FORCE),
                                    m_maxHP(DEFAULT_MAX_HP),
                                    m_HP(m_maxHP) {
}

Player::Player(const Player &other) : m_name(other.m_name),
                                      m_coins(other.m_coins),
                                      m_level(other.m_level),
                                      m_force(other.m_force),
                                      m_maxHP(other.m_maxHP),
                                      m_HP(other.m_maxHP) {
}

Player &Player::operator=(const Player &other) {
    if (this == &other) {
        return *this;
    }
    m_coins = other.m_coins;
    m_level = other.m_level;
    m_force = other.m_force;
    m_maxHP = other.m_maxHP;
    m_HP = other.m_maxHP;
    m_name = other.m_name;
    return *this;
}

Player::~Player() {}

int Player::getForce() const {
    return m_force;
}

void Player::levelUp() {
    if (this->m_level < 10) {
        this->m_level += 1;
    }
}

int Player::getLevel() const {
    return this->m_level;
}

void Player::buff(int amount) {
    if (amount > 0) {
        this->m_force += amount;
    }
}

void Player::heal(int amount) {
    if (amount > 0) {
        if (this->m_HP + amount <= this->m_maxHP) {
            this->m_HP += amount;
        } else {
            this->m_HP = this->m_maxHP;
        }
    }
}

void Player::damage(int amount) {
    if (amount > 0) {
        if (this->m_HP - amount > 0) {
            this->m_HP -= amount;
        } else {
            this->m_HP = 0;
        }
    }
}

bool Player::isKnockedOut() const {
    return !(this->m_HP);
}

void Player::addCoins(int amount) {
    if (amount > 0) {
        m_coins += amount;
    }
}

bool Player::pay(int amount) {
    if (amount < 0) {
        return true;
    }
    if (this->m_coins - amount >= 0) {
        m_coins -= amount;
        return true;
    }
    return false;
}

int Player::getAttackStrength() const {
    return this->m_force + this->m_level;
}

ostream &operator<<(ostream &os, const Player &player) {
    printPlayerDetails(os,player.m_name,player.getJob(),player.m_level,player.m_force,player.m_HP,player.m_coins);
    return os;
}
