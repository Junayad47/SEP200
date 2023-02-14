/*

Name: Junayad Bin Forhad
E-mail: jbin-forhad@myseneca.ca
Student ID: 160158218
Date: 23/07/2022

*/

#include <string>
#include "Customer.h"
using namespace std;

// Initialize the number of customers to zero
int Customer::CustomNum = 0;

void Customer::ZeroData()
{
	CustomName = "";
	CustomAddress = "";
	CustomPhoneNumber = 0;
	CustomNumber = 0;
}
Customer::Customer()
{
	CustomName = "";
	CustomAddress = "";
	CustomNumber = CustomNum;
	CustomPhoneNumber = 0;
	CustomNum++;
}

// TODO: Create all function definitions for those declared in class Customer

Customer::Customer(string CustomName_, string CustomAddress_, int CustomNumber_, long long int CustomPhoneNumber_)
{
	this->CustomName = CustomName_;
	this->CustomAddress = CustomAddress_;
	this->CustomNumber = CustomNumber_;
	this->CustomPhoneNumber = CustomPhoneNumber_;
	CustomNum++;
}

string Customer::GetName()
{
	return CustomName;
}

string Customer::GetAddress()
{
	return CustomAddress;
}

int Customer::GetCustomerNumber()
{
	return CustomNumber;
}

long long int Customer::GetPhoneNumber()
{
	return CustomPhoneNumber;
}

Err_Status Customer::SetName(string Cuss)
{
	if (Cuss.size() == 0)
		return Err_InvalidData;
	else if (CustomName.size() < 0)
		return Err_ResourceNotAvailable;

	CustomName = Cuss;
	return Err_Success;
}

Err_Status Customer::SetAddress(string Cuss2)
{
	if (Cuss2.size() == 0)
		return Err_InvalidData;
	else if (CustomAddress.size() < 0)
		return Err_ResourceNotAvailable;

	CustomAddress = Cuss2;
	return Err_Success;
}

Err_Status Customer::SetPhoneNumber(long long int Cuss3)
{
	if (Cuss3 < 0 || Cuss3 > 9999999999)
		return Err_InvalidData;
	;
	CustomPhoneNumber = Cuss3;
	return Err_Success;
}

Err_Status Customer::SetCustomerNumber(int Cuss4)
{
	if (Cuss4 < 0)
		return Err_InvalidData;
	;
	CustomNumber = Cuss4;
	return Err_Success;
}

string Customer::GetCustomerInfo()
{
	string output = "Name: ";
	output += CustomName + "endl";
	output += "Address: " + CustomAddress + "endl";
	output += "Customer Number: " + to_string(CustomNumber) + "endl";
	output += "Phone Number: " + to_string(CustomPhoneNumber) + "endl";

	return output;
}

Customer::~Customer()
{
}
