
/*

Name: Junayad Bin Forhad
E-mail: jbin-forhad@myseneca.ca
Student ID: 160158218
Date: 21/07/2022

*/

#include <iostream>
#include <string>
#include <vector>

#ifndef PLAYER_BASE
#define PLAYER_BASE

template <typename T>
class PlayerBase
{
private:
    std::string name;
    std::vector<int> dependentCards;
    double cash;

public:
    PlayerBase();
    PlayerBase(std::string name);
    PlayerBase(const PlayerBase &PlayerBase);
    PlayerBase &operator=(const PlayerBase &PlayerBase);
    ~PlayerBase();
    void setName(std::string name);
    std::string getName() const;
    void addDependentCards(int cards);
    void addDependentCard();
    int sumDependentCards() const;
    void setCash(double cash);
    double getCash() const;
    void addCash(double cash);
    void cleanUp();

    virtual T sumAllCards() const;
    virtual void addAttackCards(int cards);
    virtual void addAttackCard();

    // The players overloading the ==, < and > operators to see respectively if they are equal, if the first player has less points than the second, or if the first player has more points than the second.
    // The players overloading the << and >> to respectively add cash or remove cash from a player.
};

#endif