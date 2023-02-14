
/*

Name: Junayad Bin Forhad
E-mail: jbin-forhad@myseneca.ca
Student ID: 160158218
Date: 21/07/2022

*/

#include "PlayerAdult.h"
#include <string>
#include <vector>

// The adult player has a list of attack cards which can be integral (regular mode) or decimal (high definition mode).
//  The adult player's attack cards have a value between 1 and 15 inclusive.
//  The adult player's high definition attack cards will have values to three decimal places.
//  The adult player can be created with no attack cards.
//  The adult player can be created with a name passed by argument and no attack cards.
//  The adult player can be created from another adult player.
//  The adult player can be assigned all its data from another adult player through the = operator.
//  The adult player provides a function to add attack cards, by deleting any existing list of attack cards first.
//  The adult player provides a function to add one attack card to an existing list of attack cards.
//  The adult player provides a function to sum the attack cards.
//  The adult player provides a function to sum all cards (sum the attack cards minus sum the dependent cards).
//  The adult player cleans itself up before destruction.

// default constructor for PlayerAdult
template <typename T>
PlayerAdult<T>::PlayerAdult() : PlayerBase<T>()
{
    this->attackCards = std::vector<T>();
}

template <typename T>
PlayerAdult<T>::PlayerAdult(std::string name) : PlayerBase<T>(name)
{
    this->attackCards = std::vector<T>();
}

template <typename T>
PlayerAdult<T>::PlayerAdult(const PlayerAdult &player) : PlayerBase<T>(player)
{
    this->attackCards = player.attackCards;
}

template <typename T>
PlayerAdult<T> &PlayerAdult<T>::operator=(const PlayerAdult &player)
{
    this->name = player.name;
    this->cash = player.cash;
    this->attackCards = player.attackCards;
    this->dependentCards = player.dependentCards;

    this->attackCards = player.attackCards;
    return *this;
}

template <typename T>
PlayerAdult<T>::~PlayerAdult()
{
    this->cleanUp;
}

template <typename T>
void PlayerAdult<T>::addAttackCard()
{
    // 1 and 15 inclusive
    this->attackCards.push_back(rand() % 15 + 1);
}

template <typename T>
void PlayerAdult<T>::addAttackCards(int cards)
{
    this->attackCards.clear();
    for (int i = 0; i < cards; i++)
    {
        this->addAttackCard();
    }
}

template <typename T>
T PlayerAdult<T>::sumAttackCards() const
{
    int sum = 0;
    for (int i = 0; i < this->attackCards.size(); i++)
    {
        sum += this->attackCards[i];
    }
    return sum;
}

template <typename T>
T PlayerAdult<T>::sumAllCards() const
{

    // sum of all cards - sum of dependant cards
    return sumAttackCards() - this->sumDependentCards();
}

template <typename T>
void PlayerAdult<T>::cleanUp()
{
    this->name = "";
    this->cash = 0.0;
    this->dependentCards.clear();
    this->attackCards.clear();
}