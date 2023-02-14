/*

Name: Junayad Bin Forhad
E-mail: jbin-forhad@myseneca.ca
Student ID: 160158218
Date: 16/07/2022

*/

#ifndef SportsAssociation_h
#define SportsAssociation_h

#include <iostream>
#include "Team.h"
const int MAX = 4;
class Sport
{

    std::string name;
    const _Team *teams[MAX];
    int num = 0;

public:
    Sport(std::string);
    Sport &operator+=(const _Team &);
    void display() const;
};

#endif // SportsAssociation_h
