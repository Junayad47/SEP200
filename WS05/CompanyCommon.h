
// Name: Junayad Bin Forhad
// ID: 160158218
// Mail: jbin-forhad@myseneca.ca
// Date: 20/06/2022

// CompanyCommon.h - structures and functions for the company database

#ifndef _COMPANYBASE_H_
#define _COMPANYBASE_H_

#include <iostream>

struct StandardEmployee
{
	std::string name;
	std::string position;
	double baseSalary;
	double profitSharing;
	double performanceBonus;
	double salary;
};

struct ExecutiveEmployee
{
	std::string name;
	std::string position;
	double baseSalary;
	double stockOptionDividend;
	double perquisites; // Executive perquisites or "perks" constitute additional compensation for senior executives which are not available to other salaried employees.
	double salary;
};

const int MAX_SIZE = 1000;

// Implement the functions AddPeronnel(), FindPersonnel() and CalculateSalary() here.
// These should work for either type of database.

template <typename T>
bool AddPersonnel(T &database, int n)
{
	return database.AddPersonnel(n);
};

template <typename T, typename T2>
bool FindPersonnel(T &database, std::string name, T2 &employee)
{
	return database.FindPersonnel(name, employee);
};

template <typename T>
double CalculateSalary(T &database, std::string name)
{
	return database.CalculateSalary(name);
};

#endif // _COMPANYBASE_H_
