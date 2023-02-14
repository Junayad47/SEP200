#include <iostream>
#include <iomanip>
#include <cstring>
#include "House.h"

House::House()
{
    owner = nullptr;
    address = nullptr;
    price = 0.0;
    rooms = 0.0;
    bathrooms = 0.0;
}

House::House(const char *_owner, const char *_address, const double _rooms, const double _bathrooms, const double _price)
{
    owner = new char[strlen(_owner) + 1];
    strcpy(owner, _owner);

    address = new char[strlen(_address) + 1];
    strcpy(address, _address);

    price = _price;
    rooms = _rooms;
    bathrooms = _bathrooms;
}

House::House(const House &house)
    : owner(new char[strlen(house.owner) + 1]),
      address(new char[strlen(house.address) + 1]),
      price(house.price),
      rooms(house.rooms),
      bathrooms(house.bathrooms)
{
    strcpy(owner, house.owner);
    strcpy(address, house.address);

    price = house.price;
    rooms = house.rooms;
    bathrooms = house.bathrooms;
};

House &House::operator=(const House &house)
{
    if (this != &house)
    {
        delete[] owner;
        delete[] address;

        price = house.price;
        rooms = house.rooms;
        bathrooms = house.bathrooms;

        owner = new char[strlen(house.owner) + 1];
        strcpy(owner, house.owner);

        address = new char[strlen(house.address) + 1];
        strcpy(address, house.address);
    }

    return *this;
};

House::House(House &&house) noexcept
    : owner(nullptr),
      address(nullptr),
      price(0),
      rooms(0),
      bathrooms(0)
{
    owner = house.owner;
    address = house.address;
    price = house.price;
    rooms = house.rooms;
    bathrooms = house.bathrooms;

    house.owner = nullptr;
    house.address = nullptr;
    house.price = 0;
    house.rooms = 0;
    house.bathrooms = 0;
};

House &House::operator=(House &&house) noexcept
{
    if (this != &house)
    {
        delete[] owner;
        delete[] address;

        owner = house.owner;
        address = house.address;
        price = house.price;
        rooms = house.rooms;
        bathrooms = house.bathrooms;

        house.owner = nullptr;
        house.address = nullptr;
        house.price = 0;
        house.rooms = 0;
        house.bathrooms = 0;
    }

    return *this;
};

bool House::ChangeOwner(char *newOwner)
{
    if (newOwner && !newOwner[0])
        return false;

    delete[] owner;
    owner = new char[strlen(newOwner) + 1];
    strcpy(owner, newOwner);
    return true;
};

bool House::ChangePrice(double newPrice)
{
    if (newPrice <= 0)
        return false;
    price = newPrice;
    return true;
};

const House &House::operator+=(double amount)
{
    price += amount;
    return *this;
}

void House::DisplayInfo() const
{

    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << std::setw(11) << std::left << "Owner: " << (owner ? owner : "none") << std::endl;
    std::cout << std::setw(11) << std::left << "Address: " << (address ? address : "none") << std::endl;
    std::cout << std::setw(11) << std::left << "Rooms: " << rooms << std::endl;
    std::cout << std::setw(11) << std::left << "Bathrooms: " << bathrooms << std::endl;
    std::cout << std::setw(10) << std::left << "Price: "
              << "$" << price << std::endl;
    std::cout << std::endl;
}

House::~House()
{
    delete[] owner;
    delete[] address;
}

bool operator==(const House &house1, const House &house2)
{
    return strcmp(house1.owner, house2.owner) == 0;
};

void operator>>(House &house1, House &house2)
{
    house2 = std::move(house1);
};
