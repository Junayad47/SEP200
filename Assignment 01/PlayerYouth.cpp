
/*

Name: Junayad Bin Forhad
E-mail: jbin-forhad@myseneca.ca
Student ID: 160158218
Date: 21/07/2022

*/

#include "PlayerYouth.h"

// default constructor for PlayerYouth
template <typename T>
PlayerYouth<T>::PlayerYouth() : PlayerBase<T>()
{
    std::cout << "inside the youth player constructor\n";
    this->attackCards = std::vector<T>();
}

template <typename T>
PlayerYouth<T>::PlayerYouth(std::string name) : PlayerBase<T>(name)
{
    this->attackCards = std::vector<T>();
}

template <typename T>
PlayerYouth<T>::PlayerYouth(const PlayerYouth &player) : PlayerBase<T>(player)
{
    this->attackCards = player.attackCards;
}

template <typename T>
PlayerYouth<T> &PlayerYouth<T>::operator=(const PlayerYouth &player)
{
    this->name = player.name;
    this->cash = player.cash;
    this->attackCards = player.attackCards;
    this->dependentCards = player.dependentCards;

    this->attackCards = player.attackCards;
    return *this;
}

template <typename T>
PlayerYouth<T>::~PlayerYouth()
{
    this->cleanUp;
}

template <typename T>
void PlayerYouth<T>::addAttackCard()
{
    // 1 and 10 inclusive
    this->attackCards.push_back(rand() % 10 + 1);
}

template <typename T>
void PlayerYouth<T>::addAttackCards(int cards)
{
    this->attackCards.clear();

    for (int i = 0; i < cards; i++)
    {
        this->addAttackCard();
    }
}

template <typename T>
T PlayerYouth<T>::sumAttackCards() const
{
    int sum = 0;
    for (int i = 0; i < this->attackCards.size(); i++)
    {
        sum += this->attackCards[i];
    }
    return sum;
}

template <typename T>
T PlayerYouth<T>::sumAllCards() const
{
    // sum of all cards - sum of dependant cards
    return sumAttackCards() - this->sumDependentCards();
}

template <typename T>
void PlayerYouth<T>::cleanUp()
{
    this->name = "";
    this->cash = 0.0;
    this->dependentCards.clear();
    this->attackCards.clear();
}