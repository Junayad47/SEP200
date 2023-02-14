/*

Name: Junayad Bin Forhad
E-mail: jbin-forhad@myseneca.ca
Student ID: 160158218
Date: 16/07/2022

*/

#include "BaseballTeam.h"

Baseball::Baseball(std::string _name, int _wins, unsigned int _losses)
{

    name = _name;
    wins = _wins;
    losses = _losses;
    WinningPercentage = (wins + losses) == 0 ? 0 : float(wins) / float(wins + losses);
}

Err_Status Baseball::display() const
{

    Err_Status err = name == "" || (wins == 0 && losses == 0) ? Err_Undefined : Err_Success;

    if (err == Err_Success)
        std::cout << name << " has " << wins << " wins and " << losses << " losses for a winning percentage of " << winingRate << std::endl;
    else
        std::cout << "Invalid data" << std::endl;

    return err;
}

bool Baseball::operator==(const Team &other) const
{

    const Baseball *team = dynamic_cast<const Baseball *>(&other);

    return team ? (this->WinningPercentage == team->WinningPercentage) : false;
}
