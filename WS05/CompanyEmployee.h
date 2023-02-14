
// Name: Junayad Bin Forhad
// ID: 160158218
// Mail: jbin-forhad@myseneca.ca
// Date: 20/06/2022

#ifndef _COMPANYEMPLOYEE_H_
#define _COMPANYEMPLOYEE_H_

#include <iostream>
#include "CompanyCommon.h"

class CompanyEmployee
{
private:
  StandardEmployee *employees;
  int totalEmployees;

public:
  CompanyEmployee();
  ~CompanyEmployee();
  bool AddPersonnel(int n);
  bool FindPersonnel(std::string name, StandardEmployee &employee);
  double CalculateSalary(std::string name);
};

#endif