/*

Name: Junayad Bin Forhad
E-mail: jbin-forhad@myseneca.ca
Student ID: 160158218
Date: 16/07/2022

*/

#include "SportsAssociation.h"

Sport::Sport(std::string name) : name(name) {}
Sport &Sport::operator+=(const _Team &team)
{
    if (num < MAX)
    {

        teams[num++] = &team;

        for (int i = 0; i < num - 1; ++i)
        {
            if (*teams[i] == team)
            {
                std::cout << team.GetName() << " is similar to " << teams[i]->GetName() << "." << std::endl;
            }
        }
    }
    else
    {

        std::cout << "The maximum team limit has been reached and hence we cannot add more teams" << std::endl;
    }

    return *this;
}

void SportsAssociation::display() const
{

    std::cout << std::endl
              << name << " has following teams:" << std::endl;

    for (int i = 0; i < numTeams; ++i)
    {
        Err_Status err = teams[i]->display();
    }
}