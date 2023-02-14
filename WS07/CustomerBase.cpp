/*

Name: Junayad Bin Forhad
E-mail: jbin-forhad@myseneca.ca
Student ID: 160158218
Date: 23/07/2022

*/

// CustomerBase.cpp - The main function for a map of customers

#include <iostream>
#include <map>
#include <cstdio>
#include <string>
#include "Customer.h"

using namespace std;

Customer *findCustomer(long long int phnum, map<long long int, Customer> &customerMap)
{
	map<long long int, Customer>::iterator itr;
	itr = customerMap.find(phnum);
	Customer *cu = NULL;
	if (itr != customerMap.end())
	{
		// found the value
		cu = &(itr->second);
	}

	return cu;
}

int main()
{
	map<long long int, Customer> customerMap;
	char first_name[] = "Aaaa";
	char last_name[] = "Bbbb";
	int street_no = 0;
	char street_name[] = "Cccc";
	long long int Phone_no = 1111111110;

	// Build a database of 160,000 entries
	for (int i = 0; i < 20; ++i)
	{
		++first_name[0];
		++last_name[0];
		++street_name[0];
		first_name[1] = 'a';
		last_name[1] = 'b';
		street_name[1] = 'c';
		for (int j = 0; j < 20; ++j)
		{
			++first_name[1];
			++last_name[1];
			++street_name[1];
			first_name[2] = 'a';
			last_name[2] = 'b';
			street_name[2] = 'c';
			for (int k = 0; k < 20; ++k)
			{
				++first_name[2];
				++last_name[2];
				++street_name[2];
				++street_no;
				first_name[3] = 'a';
				last_name[3] = 'b';
				street_name[3] = 'c';
				for (int l = 0; l < 20; ++l)
				{
					++first_name[3];
					++last_name[3];
					++street_name[3];
					++Phone_no;
					char name[16];
					char addr[32];
					sprintf(name, "%s %s", first_name, last_name);
					sprintf(addr, "%d %s Drive", street_no, street_name);
					// cout << name << " " << addr << " " << Phone_no << endl;
					Customer cuss_;
					Err_Status err;
					err = cuss_.SetName(name);
					if (err)
						cout << "Couldn't set the name , produced error:" << err << endl;
					err = cuss_.SetAddress(addr);
					if (err)
						cout << "Couldn't set the address, produced error:" << err << endl;
					err = cuss_.SetPhoneNumber(Phone_no);
					if (err)
						cout << "Couldn't set the Phone_no, produced error:" << err << endl;
					// cout<<"Customer id is:\n"<<c.getCustomerNumber();
					// TODO: Insert this customer into the customerMap database
					//       You have enough information to create a customer object
					customerMap.insert(pair<long long int, Customer>(Phone_no, cuss_));
				}
			}
		}
	}

	// TODO: Find and print out information for the customer with phone number 1111112222
	//       Print an error if you cannot find the customer
	long long int Phone = 1111112222;
	Err_Status err;
	Customer *cus = findCustomer(Phone, customerMap);
	if (cus)
		cout << "\n| Customer info |\n"
			 << cus->GetCustomerInfo();

	// TODO: Change that customer's name to "Darryl Smith", the phone number to 9051112222,
	//       and the address to "1 Bloor Street"
	//       Then print out the information for this customer
	long long int NewPhone = 9051112222;
	err = cus->SetName("Darryl Smith");
	if (err)
		cout << "Couldn't set the name , produced error:" << err << endl;
	err = cus->SetPhoneNumber(NewPhone);
	if (err)
		cout << "Couldn't set the Phone_no, produced error:" << err << endl;
	err = cus->SetAddress("1 Bloor Street");
	if (err)
		cout << "Couldn't set the address, produced error:" << err << endl;

	if (!customerMap.erase(Phone))
		cout << Phone << " not found in the database" << endl;
	customerMap.insert(pair<long long int, Customer>(NewPhone, *cus));
	cus = findCustomer(NewPhone, customerMap);
	if (cus)
		cout << "\n| Customer info |\n"
			 << cus->GetCustomerInfo();

	// TODO: Remove this customer from the database
	if (!customerMap.erase(NewPhone))
		cout << "Customer with phone number: " << NewPhone << " is not found !!\n"
			 << endl;

	// TODO: Try to find this customer, print an error if you cannot, print the customer information if you can
	cus = findCustomer(NewPhone, customerMap);
	if (cus)
		cout << "\n| Customer info |\n"
			 << cus->GetCustomerInfo();
	else
		cout << "\nCustomer with phone number: " << NewPhone << " is not found !!\n"
			 << endl;

	// TODO: Zero all data before exiting
	map<long long int, Customer>::iterator itr;
	for (itr = customerMap.begin(); itr != customerMap.end(); ++itr)
	{
		(itr->second).ZeroData();
	}

	// TODO: Now try to find and print out information for the customer with phone number 1111111112
	//       Print an error if you cannot find the customer
	Phone = 1111111112;
	cus = findCustomer(Phone, customerMap);
	if (cus)
		cout << "\n| Customer info |\n"
			 << cus->GetCustomerInfo();
	else
		cout << "Customer with phone number: " << Phone << " is not found !!\n"
			 << endl;

	return 0;
}
