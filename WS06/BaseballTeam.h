/*

Name: Junayad Bin Forhad
E-mail: jbin-forhad@myseneca.ca
Student ID: 160158218
Date: 16/07/2022

*/

#ifndef BaseballTeam_h
#define BaseballTeam_h

#include "Team.h"
#include <iostream>
#include <string>
#include <stdio.h>

class Baseball : public Team
{
    std::string name;
    int wins;
    int losses;
    double WinningPercentage;

public:
    BaseballTeam(std::string, int, int);
    std::string GetName() const;
    Err_Status display() const;
    bool operator==(const Team &) const;
};

#endif // BaseballTeam_h
