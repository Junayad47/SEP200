// Book.cpp - function definitions for Book.h

// Name: Junayad Bin Forhad
// ID: 160158218
// Mail: jbin-forhad@myseneca.ca
// Date: 10/06/2022

#include "Book.h"

using namespace std;

Book::Book(std::string _title, int _numAuthors, double _price, std::string *_authors) : Item(_title, _numAuthors, _price, _authors)
{
}

double CalculateCost(double price)
{
    double TaxAndPenaltyCost = Item::CalculateCost;
}
