
/*

Name: Junayad Bin Forhad
E-mail: jbin-forhad@myseneca.ca
Student ID: 160158218
Date: 21/07/2022

*/

#ifndef PlayerBaseCPP
#define PlayerBaseCPP

#include "PlayerBase.h"
#include <iostream>

using namespace std;

// explicit instantiations
template class PlayerBase<int>;
template class PlayerBase<double>;

template <typename T>
PlayerBase<T>::PlayerBase() : name(""), cash(1000.0)
{
    this->dependentCards = std::vector<int>();
}

template <typename T>
PlayerBase<T>::PlayerBase(std::string name)
{
    this->name = name;
    this->cash = 1000.0;
    this->dependentCards = std::vector<int>();
}

// copy constructor
template <typename T>
PlayerBase<T>::PlayerBase(const PlayerBase &player)
{
    this->name = player.name;
    this->cash = player.cash;
    this->dependentCards = player.dependentCards;
}

// getters and setters
template <typename T>
std::string PlayerBase<T>::getName() const
{
    return this->name;
}

template <typename T>
void PlayerBase<T>::setName(std::string name)
{
    this->name = name;
}

template <typename T>
void PlayerBase<T>::setCash(double cash)
{
    this->cash = cash;
}

template <typename T>
double PlayerBase<T>::getCash() const
{
    return this->cash;
}

template <typename T>
void PlayerBase<T>::addCash(double cash)
{
    this->cash += cash;
}

// void cleanUp();
template <typename T>
void PlayerBase<T>::cleanUp()
{
    this->name = "";
    this->cash = 0.0;
    this->dependentCards.clear();
}

// destructor
template <typename T>
PlayerBase<T>::~PlayerBase()
{
    this->cleanUp();
}

// add dependant cards
template <typename T>
void PlayerBase<T>::addDependentCards(int cards)
{
    // a function to add dependent cards, by deleting any existing list of dependent cards first.
    this->dependentCards.clear();
    for (int i = 0; i < cards; i++)
    {
        // 1 and 5 inclusive
        this->addDependentCard();
    }
}

template <typename T>
void PlayerBase<T>::addDependentCard()
{
    // a function to add one dependent card to an existing list of dependent cards.
    this->dependentCards.push_back(rand() % 5 + 1);
    // std::cout << "added the dependant card ... "<< card << endl;
}

// sum dependant cards
template <typename T>
int PlayerBase<T>::sumDependentCards() const
{
    int sum = 0;
    for (int i = 0; i < this->dependentCards.size(); i++)
    {
        sum += this->dependentCards[i];
    }
    return sum;
}

/*          Defined in derived classes          */
template <typename T>
T PlayerBase<T>::sumAllCards() const
{
}

template <typename T>
void PlayerBase<T>::addAttackCard()
{
}

template <typename T>
void PlayerBase<T>::addAttackCards(int cards)
{
}

/*           Overload operators                 */
// overload = operator
template <typename T>
PlayerBase<T> &PlayerBase<T>::operator=(const PlayerBase<T> &player)
{
    this->name = player.name;
    this->cash = player.cash;
    this->dependentCards = player.dependentCards;
    return *this;
}

// overload comparison operators
// The players overloading the ==, < and > operators to see respectively if they are equal, if the first player has less points than the second, or if the first player has more points than the second.
template <typename T>
bool operator==(const PlayerBase<T> &PlayerBase1, const PlayerBase<T> &PlayerBase2)
{
    return PlayerBase1.cash == PlayerBase2.cash;
}

template <typename T>
bool operator<(const PlayerBase<T> &PlayerBase1, const PlayerBase<T> &PlayerBase2)
{
    return PlayerBase1.cash < PlayerBase2.cash;
}

template <typename T>
bool operator>(const PlayerBase<T> &PlayerBase1, const PlayerBase<T> &PlayerBase2)
{
    return PlayerBase1.cash > PlayerBase2.cash;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const PlayerBase<T> &playerBase)
{

    // The players overloading the << and >> to respectively add cash or remove cash from a player.
    // os << playerBase.cash;
    // playerBase.cash = 0;
    return os;
}

template <typename T>
std::istream &operator>>(std::istream &is, PlayerBase<T> &playerBase)
{
    // read cash from the console
    double cash;
    is >> cash;

    playerBase.addCash(cash);
    return is;
}

#endif