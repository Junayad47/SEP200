/*

Name: Junayad Bin Forhad
E-mail: jbin-forhad@myseneca.ca
Student ID: 160158218
Date: 16/07/2022

*/

#include "HockeyTeam.h"

using namespace std;

Hockey::Hockey(std::string _name, int _wins, int _ties, int _losses)
{
    name = _name;
    wins = _wins;
    ties = _ties;
    losses = _losses;
    total = (2 * wins + ties);
}

std::string Hockey::GetName() const
{
    return name;
}

Err_Status Hockey::display() const
{
    Err_Status Stat = Err_Success;
    if (name == "")
    {
        Stat = Err_Undefined;
        cout << "No name's defined";
    }
    else if (wins < 0 || losses < 0 || ties < 0)
    {
        Stat = Err_OutOfBounds;
        cout << "Wrong number of wins or losses";
    }
    else if (Total_Points < 0.0)
    {
        Stat = Err_Calculation;
        cout << "Calculation error";
    }
    else
    {
        cout << name << " has " << wins << " wins, " << ties << " ties, and " << losses << " losses for " << Total_Points << " points.";
    }
    return Stat;
}

bool Hockey::operator==(const Team &team) const
{
    bool Type = false;
    bool Total_Points = false;
    const Hockey *teamCast = dynamic_cast<const Hockey *>(&team);
    if (type(team) == type(*this))
        Type = true;
    if (Type)
    {
        if (Total_Points == teamCast->Total_Points)
            total = true;
    }
    return total;
}
