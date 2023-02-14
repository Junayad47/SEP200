/*

Name: Junayad Bin Forhad
E-mail: jbin-forhad@myseneca.ca
Student ID: 160158218
Date: 23/07/2022

*/

#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include <iostream>
#include <string>
using namespace std;

enum Err_Status
{
	Err_Success,
	Err_InvalidData,
	Err_ResourceNotAvailable
};

class Customer
{
	// TODO: Add all variables, including any class variables. Your phone number has to be a long long int

	string CustomName;
	int CustomNumber;
	string CustomAddress;
	long long int CustomPhoneNumber;
	static int CustomNum;

public:
	// TODO: A default constructor
	Customer();
	Customer::Customer(string CustomName, string CustomAddress, int CustomNumber, long long int CustomPhoneNumber);
	~Customer();

	// TODO: A constructor to accept the name, address and phone number of a customer
	// TODO: Get functions for name, address, the customer number, and the phone number
	string GetName();
	string GetAddress();
	long long int GetPhoneNumber();
	int GetCustomerNumber();

	// TODO: A function to zero all data
	void ZeroData();
	Err_Status SetName(string Cuss);
	Err_Status SetAddress(string Cuss2);
	Err_Status SetPhoneNumber(long long int Cuss3);

	// TODO: Set functions for name, address and phone number. These functions should return an error status
	Err_Status SetCustomerNumber(int Cusss4);

	// TODO: A get information function to return the customer's name, address, customer number and phone number
	string GetCustomerInfo();
};

#endif // _CUSTOMER_H_
