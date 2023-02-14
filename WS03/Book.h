
// Name: Junayad Bin Forhad
// ID: 160158218
// Mail: jbin-forhad@myseneca.ca
// Date: 10/06/2022

#ifndef _BOOK_H_
#define _BOOK_H_

#include <iostream>
#include "GenericItem.h"

class Book : public Item
{
public:
    Book(std::string _title, int _numAuthors, double _price, std::string *_authors);
    double CalculateCost() const;
    void display(std::ostream &os) const;
    ~Book();
};

std::ostream &operator<<(std::ostream &os, Book &student);

#endif // _BOOK_H_