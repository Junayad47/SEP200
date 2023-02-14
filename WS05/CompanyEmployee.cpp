
// Name: Junayad Bin Forhad
// ID: 160158218
// Mail: jbin-forhad@myseneca.ca
// Date: 20/06/2022

#include "CompanyEmployee.h"

CompanyEmployee::CompanyEmployee()
{
  employees = nullptr;
  totalEmployees = 0;
}

bool CompanyEmployee::AddPersonnel(int n)
{
  if (totalEmployees + n > MAX_SIZE)
    return false;

  StandardEmployee *_employees = new StandardEmployee[totalEmployees + n];
  for (int i = 0; i < totalEmployees; i++)
  {
    _employees[i] = employees[i];
  }

  for (int i = 0; i < n; i++)
  {
    StandardEmployee employee;

    std::cout << "Enter the employee's name: ";
    std::getline(std::cin, employee.name);

    std::cout << "Enter the employee's position: ";
    std::getline(std::cin, employee.position);

    std::cout << "Enter the employee's base salary: ";
    std::cin >> employee.baseSalary;
    std::cin.ignore(256, '\n');

    std::cout << "Enter the employee's annual profit sharing amount: ";
    std::cin >> employee.profitSharing;
    std::cin.ignore(256, '\n');

    std::cout << "Enter the employee's annual performance bonus: ";
    std::cin >> employee.performanceBonus;
    std::cout << std::endl;
    std::cin.ignore(256, '\n');

    employee.salary = employee.baseSalary + employee.profitSharing + employee.performanceBonus;

    _employees[totalEmployees + i] = employee;
  }
  std::cout << std::endl;
  delete[] employees;
  employees = _employees;
  totalEmployees += n;

  return true;
}

bool CompanyEmployee::FindPersonnel(std::string name, StandardEmployee &employee)
{
  bool found = false;
  for (int i = 0; i < totalEmployees; i++)
  {
    if (employees[i].name == name)
    {
      found = true;
      employee = employees[i];
      break;
    }
  }
  return found;
}

double CompanyEmployee::CalculateSalary(std::string name)
{
  double salary = 0.0;

  for (int i = 0; i < totalEmployees; i++)
  {
    if (employees[i].name == name)
    {
      salary = employees[i].salary;
      break;
    }
  }
  return salary;
}

CompanyEmployee::~CompanyEmployee()
{
  delete[] employees;
}
