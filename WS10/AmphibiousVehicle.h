//
// Name: Junayad Bin Forhad, 160158218
// E-mail: jbin-forhad@myseneca.ca
// Date: 10th August, 2022
//

// AmphibiousVehicle.h - class declaration for an amphibious vehicle

#ifndef _AMPHIBIOUSVEHICLE_H_
#define _AMPHIBIOUSVEHICLE_H_

#include <iostream>

class AmphibiousVehicle : public Boat, public Automobile
{
	std::string Name;
	unsigned short Var;

public:
	static const unsigned short Empty;
	static const unsigned short Boat;
	static const unsigned short AutoM;

	AmphibiousVehicle(std::string Name_, double StartingFuel);
	Err_Status AddFuel(double Amount_);
	double GetFuel();
	std::string GetName();
	double GetCost();
	Err_Status Travel(double Distance_);
	void SetMode(const unsigned short Var1);
	void UnsetMode(const unsigned short Var2);
};

#endif // _AMPHIBIOUSVEHICLE_H_