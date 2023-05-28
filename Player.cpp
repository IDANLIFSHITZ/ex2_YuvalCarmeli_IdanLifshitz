//
// Created by yuval on 5/28/2023.
//
#include <cassert>
#include "Player.h"
#include "utilities.h"

//c'tor with name, maxHP and strength
Player::Player(std::string name, int maxHP, int strength) : m_level(1), m_maxHP(maxHP), m_currentHP(maxHP),
                                                                    m_strength(strength), m_coins(0), m_name(name)
                                                                    {
    if (maxHP <= 0)
    {
        m_currentHP = 100;
        m_maxHP = 100;
    }
    if (strength < 0)
    {
        m_strength = 5;
    }
}

void Player::printInfo() const
{
    printPlayerInfo(m_name.c_str(), m_level, m_currentHP, m_strength, m_coins);
}

void Player::levelUp()
{
    if (m_level < WIN_LEVEL)
    {
        m_level++;
    }
}

int Player::getLevel() const
{
    return m_level;
}

void Player::buff(int amount)
{
    if (amount < 0)
    {
        return;
    }
    m_strength += amount;
}
void Player::heal(int amount)
{
    if(amount < 0)
    {
        return;
    }
    if (m_currentHP + amount >= m_maxHP)
    {
        m_currentHP = m_maxHP;
        return;
    }
    m_currentHP += amount;
}

void Player::damage(int amount)
{
    if(amount < 0)
    {
        return;
    }
    if (m_currentHP - amount <= 0)
    {
        m_currentHP = 0;
        return;
    }
    m_currentHP -= amount;
}

bool Player::isKnockedOut() const
{
    if (m_currentHP == 0)
    {
        return true;
    }
    return false;
}

void Player::addCoins(int amount)
{
    if(amount < 0)
    {
        return;
    }
    m_coins += amount;
}

bool Player::pay(int amount)
{
    if (m_coins - amount < 0 || amount < 0)
    {
        return false;
    }
    m_coins -= amount;
    return true;
}

int Player::getAttackStrength() const
{
    return m_strength + m_level;
}