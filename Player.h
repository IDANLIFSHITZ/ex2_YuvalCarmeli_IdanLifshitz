//
// Created by yuval on 5/28/2023.
//

#include <string>

#ifndef PLAYER_H
#define PLAYER_H


class Player {

private:
    int m_level; // between 1 and 10, included
    int m_maxHP; // positive, non-zero integer
    int m_currentHP; // between 0 and m_maxHP, included
    int m_strength; // non-negative integer
    int m_coins; // non-negative integer
    std::string m_name; // english letters only with no spaces

public:
    static const int WIN_LEVEL = 10;

    //c'tors- default c'tor, c'tor with name, maxHP and strength
    Player(std::string name, int maxHP = 100, int strength = 5);
    Player() = default;


    //the big three- default copy c'tor, default assignment operator, default d'tor
    Player(const Player& player) = default;
    Player& operator=(const Player& player) = default;
    ~Player() = default;



    /*
     * mambers functions segment:
     */


    /*
     * @return void
     * @note prints the player's info in the format given by the exercise and printed in the "printPlayerInfo"
     * function in "utilities.h"
     */
    void printInfo() const;

    /*
     * @return void
     * @note increases the player's level by 1
     * @note if the player's level is already at 10, do nothing
     */
    void levelUp();

    /*
     * @return the player's level
     */
    int getLevel() const;

    /*
     * @param amount- the amount to buff the player's strength
     * @return void
     * @note if amount is negative, do nothing
     */
    void buff(int amount);

    /*
     * @param amount- the amount to heal the player's HP
     * @return void
     * @note if amount is negative, do nothing
     * @note if the player's HP is already at maxHP, do nothing
     */
    void heal(int amount);

    /*
     * @param amount- the amount to damage the player's HP
     * @return void
     * @note if amount is negative, do nothing
     * @note if the player's HP is already at 0, do nothing
     */
    void damage(int amount);

    /*
     * @return true if the player is knocked out (HP is 0), false otherwise
     */
    bool isKnockedOut() const;

    /*
     * @param amount- the amount to add to the player's coins
     * @return void
     * @note if amount is negative, do nothing
     */
    void addCoins(int amount);

    /*
     * @param amount- the amount to pay from the player's coins
     * @return true if the player had enough coins to pay, false otherwise
     * @note if amount is negative, do nothing
     */
    bool pay(int amount);

    /*
     * @return the player's attack strength (level + strength)
     */
    int getAttackStrength() const;
};


#endif //PLAYER_H
