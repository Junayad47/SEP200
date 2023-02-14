
//*
// Sep 200, Professor Mufleh Al-Shatnawi, Ph.D., P.Eng
// Workshop: 01
// Student Name: Junayad Bin Forhad
// Id  : 160158218
//*

// BankManager.h - class declaration for a bank manager

#ifndef _BANK_MANAGER_H
#define _BANK_MANAGER_H
#include <iostream>
#include "InvestmentAccount.h"

class BankManager
{
	std::string name;
	int branchNumber;
	int employeeNumber;

public:
	BankManager();
	BankManager(std::string name, int branch, int employee);
	void OverrideName(InvestmentAccount &account, std::string name);
	void AddCash(InvestmentAccount &account, double cash);
	void RemoveCash(InvestmentAccount &account, double cash);
	std::ostream &PrintReport(InvestmentAccount &account) const;
	~BankManager();
};

bool operator==(InvestmentAccount &_account, InvestmentAccount &_account2);

#endif //_BANK_MANAGER_H