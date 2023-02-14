
// Name: Junayad Bin Forhad
// ID: 160158218
// Mail: jbin-forhad@myseneca.ca
// Date: 20/06/2022

#include "CompanyExecutive.h"

CompanyExecutive::CompanyExecutive()
{
  executives = nullptr;
  totalExecutives = 0;
}

bool CompanyExecutive::AddPersonnel(int n)
{
  if (totalExecutives + n > MAX_SIZE)
    return false;

  ExecutiveEmployee *_executives = new ExecutiveEmployee[totalExecutives + n];
  for (int i = 0; i < totalExecutives; i++)
  {
    _executives[i] = executives[i];
  }

  for (int i = 0; i < n; i++)
  {
    ExecutiveEmployee executive;

    std::cout << "Enter the executive's name: ";
    std::getline(std::cin, executive.name);

    std::cout << "Enter the executive's position: ";
    std::getline(std::cin, executive.position);

    std::cout << "Enter the executive's base salary: ";
    std::cin >> executive.baseSalary;
    std::cin.ignore(256, '\n');

    std::cout << "Enter the executive's annual stock option dividend: ";
    std::cin >> executive.stockOptionDividend;
    std::cin.ignore(256, '\n');

    std::cout << "Enter the executive's annual perquisites: ";
    std::cin >> executive.perquisites;
    std::cout << std::endl;
    std::cin.ignore(256, '\n');

    executive.salary = executive.baseSalary + executive.stockOptionDividend + executive.perquisites;

    _executives[totalExecutives + i] = executive;
  }
  std::cout << std::endl;
  delete[] executives;
  executives = _executives;
  totalExecutives += n;

  return true;
}

bool CompanyExecutive::FindPersonnel(std::string name, ExecutiveEmployee &executive)
{
  bool found = false;
  for (int i = 0; i < totalExecutives; i++)
  {
    if (executives[i].name == name)
    {
      found = true;
      executive = executives[i];
      break;
    }
  }
  return found;
}

double CompanyExecutive::CalculateSalary(std::string name)
{
  double salary = 0.0;

  for (int i = 0; i < totalExecutives; i++)
  {
    if (executives[i].name == name)
    {
      salary = executives[i].salary;
      break;
    }
  }
  return salary;
}

CompanyExecutive::~CompanyExecutive()
{
  delete[] executives;
}
