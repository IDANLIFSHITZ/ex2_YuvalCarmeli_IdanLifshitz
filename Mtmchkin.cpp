//
// Created by yuval on 5/28/2023.
//
#include "Mtmchkin.h"

#define WIN_LEVEL 10

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards): m_numOfCards(numOfCards),
                                                                                    m_currentCardIndex(0),
                                                                                    m_gameStatus(GameStatus::MidGame)
                                                                                    {
    if (playerName)
    {
        m_player = Player(std::string(playerName));
    }
    else
    {
        m_player = Player();
    }

    m_cardsArray = new Card[numOfCards];
    for (int i = 0; i < numOfCards; ++i)
    {
        m_cardsArray[i] = cardsArray[i];
    }
}


Mtmchkin::Mtmchkin(const Mtmchkin& other): m_player(other.m_player), m_numOfCards(other.m_numOfCards),
                                           m_currentCardIndex(other.m_currentCardIndex)
{
    m_cardsArray = new Card[m_numOfCards];
    for (int i = 0; i < m_numOfCards; ++i) {
        m_cardsArray[i] = other.m_cardsArray[i];
    }
}

Mtmchkin& Mtmchkin::operator=(const Mtmchkin& other) {
    if (this == &other) {
        return *this;
    }
    delete[] m_cardsArray;
    m_player = other.m_player;
    m_numOfCards = other.m_numOfCards;
    m_currentCardIndex = other.m_currentCardIndex;
    m_cardsArray = new Card[m_numOfCards];
    for (int i = 0; i < m_numOfCards; ++i) {
        m_cardsArray[i] = other.m_cardsArray[i];
    }
    return *this;
}

Mtmchkin::~Mtmchkin() {
    delete[] m_cardsArray;
}


void Mtmchkin::playNextCard()
{
    if (m_currentCardIndex == m_numOfCards)
    {
        m_currentCardIndex = 0;
    }

    m_cardsArray[m_currentCardIndex].printInfo();
    m_cardsArray[m_currentCardIndex].applyEncounter(m_player);
    m_player.printInfo();
    m_currentCardIndex++;

    if (m_player.getLevel() == WIN_LEVEL)
    {
        m_gameStatus = GameStatus::Win;
    }
    else if (m_player.isKnockedOut())
    {
        m_gameStatus = GameStatus::Loss;
    }

}

bool Mtmchkin::isOver() const
{
    if (getGameStatus() != GameStatus::MidGame)
    {
        return true;
    }
    return false;
}

GameStatus Mtmchkin::getGameStatus() const
{
    return m_gameStatus;
}