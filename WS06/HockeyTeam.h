
/*

Name: Junayad Bin Forhad
E-mail: jbin-forhad@myseneca.ca
Student ID: 160158218
Date: 16/07/2022

*/

#ifndef HockeyTeam_h
#define HockeyTeam_h

#include "Team.h"
#include <iostream>
#include <string>
#include <stdio.h>

class Hockey : public Team
{
    std::string name;
    int wins;
    int ties;
    int losses;
    double total;

public:
    Hockey(std::string, int, int, int);
    std::string GetName() const;
    Err_Status display() const;
    bool operator==(const Team &) const;
};

#endif // HockeyTeam_h
