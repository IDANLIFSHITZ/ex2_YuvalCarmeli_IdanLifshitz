//
// Created by yuval on 5/28/2023.
//

#ifndef PLAYER_H
#define PLAYER_H


class Player {
    //munchkin player
private:
    int m_level;
    int m_maxHP;
    int m_currentHP;
    int m_strength;
    int m_coins;
    std::string m_name;
public:

    //c'tors- default c'tor, c'tor with name, maxHP and strength
    Player(const std::string& name, int maxHP, int strength);
    Player() = default;

    //the big three- default copy c'tor, default assignment operator, default d'tor
    Player(const Player& player) = default;
    Player& operator=(const Player& player) = default;
    ~Player() = default;

    //methods
    void printInfo() const;
    void levelUp();
    int getLevel() const;
    void buff(int amount);
    void heal(int amount);
    void damage(int amount);
    bool isKnockedOut() const;
    void addCoins(int amount);
    void pay(int amount);
    int getAttackStrength() const;
};


#endif //PLAYER_H
