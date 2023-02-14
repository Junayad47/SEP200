// GenericItem.h - class declaration for a Item

// Name: Junayad Bin Forhad
// ID: 160158218
// Mail: jbin-forhad@myseneca.ca
// Date: 10/06/2022

#ifndef _GENERICITEM_H_
#define _GENERICITEM_H_
#include <iostream>

class Item
{
    // these are common to this class and all derived classes
    std::string title;
    int numAuthors;
    std::string *authors;
    double price;

protected: // for derived classes only
    std::string GetTitle() const;
    int GetNumberOfAuthors() const;
    double GetPrice() const;

public:
    Item(std::string _title, int _numAuthors, std::string *_authors);
    void CalculateCost();
    void Getprice2();
    void display(std::ostream &os) const;
    ~Item();
};

std::ostream &operator<<(std::ostream &os, Item &item);

#endif // _ITEM_H_
