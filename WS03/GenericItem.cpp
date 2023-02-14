// GenericItem.cpp - function definitions for the Item class

// Name: Junayad Bin Forhad
// ID: 160158218
// Mail: jbin-forhad@myseneca.ca
// Date: 10/06/2022

#include "GenericItem.h"

using namespace std;

Item::Item(std::string _title, int _numAuthors, std::string *_authors)
{
    title = _title;
    numAuthors = _numAuthors;
    if (numAuthors > 0)
    {
        authors = new std::string[numAuthors];
        for (int i = 0; i < numAuthors; ++i)
        {
            authors[i] = _authors[i];
        }
    }
    else
    {
        authors = nullptr;
    }
}

void Getprice2(double _price)
{
    price = _price;
}

double CalculateCost(double price)
{
    return price;
}

void Item::display(std::ostream &os) const
{
    os << endl
       << endl;
    os << "Title" << title << endl;
    for (int i = 0; i < numAuthors; ++i)
    {
        os << "Authors" << authors[i];
    }
    os << "." << endl;
    os << "Price" << price << endl;
}

std::ostream &operator<<(std::ostream &os, Item &item)
{
    item.display(os);
    return os;
}

Item::~Item()
{
    delete[] authors;
    authors = nullptr;
};