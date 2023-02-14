
// Name: Junayad Bin Forhad
// ID: 160158218
// Mail: jbin-forhad@myseneca.ca
// Date: 20/06/2022

#ifndef _COMPANYEXECUTIVE_H_
#define _COMPANYEXECUTIVE_H_

#include <iostream>
#include "CompanyCommon.h"

class CompanyExecutive
{
private:
  ExecutiveEmployee *executives;
  int totalExecutives;

public:
  CompanyExecutive();
  ~CompanyExecutive();
  bool AddPersonnel(int n);
  bool FindPersonnel(std::string name, ExecutiveEmployee &executive);
  double CalculateSalary(std::string name);
  void debug();
};

#endif