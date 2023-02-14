
//*
// Sep 200, Professor Mufleh Al-Shatnawi, Ph.D., P.Eng
// Workshop: 01
// Student Name: Junayad Bin Forhad
// Id  : 160158218
//*

// InvestmentAccount.cpp - function definitions for an investment account

#include <iostream>
#include "BankManager.h"
#include "InvestmentAccount.h"

using namespace std;

InvestmentAccount::InvestmentAccount()
{
	cash = 0.0;
	name = "";
}

InvestmentAccount::InvestmentAccount(std::string name, double cash)
{
	this->name = name;
	this->cash = cash;
}

bool InvestmentAccount::PurchaseStocks(double amount)
{
	bool success = true;
	if (this->cash < amount)
	{
		success = false;
	}
	else
	{
		this->cash -= amount;
		stocks += amount;
	}

	return success;
}

bool InvestmentAccount::SellStocks(double amount)
{
	bool success = true;
	if (stocks < amount)
	{
		success = false;
	}
	else
	{
		this->cash += amount;
		stocks -= amount;
	}
	return success;
}

std::string InvestmentAccount::GetName() const
{
	return name;
}

double InvestmentAccount::GetValue() const
{
	return cash + stocks;
}

double InvestmentAccount::GetStocks() const
{
	return stocks;
}

double InvestmentAccount::GetCash() const
{
	return cash;
}

// Implement the overload of the += operator
// This should add cash to the investment account
// If the amount to be added is negative, print out the error message "Invalid transaction"
// Do not forget the function prototype in the header file InvestmentAccount.h

InvestmentAccount &InvestmentAccount::operator+=(double _cash)
{
	if (_cash > 0)
	{
		cash += _cash;
		return *this;
	}
	else
	{
		cout << "Invalid Transaction" << endl;
	}
}

// Implement the overload of the -= operator
// This should withdraw cash from the investment account
// If the amount to be withdrawn is negative, print out the error message "Invalid transaction"
// If there isn't enough cash in the account, print out the error message "Not enough funds"
// Do not forget the function prototype in the header file InvestmentAccount.h

InvestmentAccount &InvestmentAccount::operator-=(double _cash)
{
	if (_cash > 0 && _cash < cash)
	{
		cash -= _cash;
		return *this;
	}
	else if (_cash > cash || _cash < 0)
	{
		cout << "Not enough funds in this account for Kamla Patel." << endl;
	}
}

InvestmentAccount::~InvestmentAccount()
{
	// wipe out all information
	cash = 0;
	stocks = 0;
	std::string name = "";
}
