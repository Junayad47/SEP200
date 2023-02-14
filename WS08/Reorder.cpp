//*
// Name : Junayad Bin Forhad
// E-mail : jbin-forhad@myseneca.ca
// Student ID : 160158218
// Date : 30 / 07 / 2022
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include "Stack.h"

using namespace std;
void Assign(int NewArr[], int Array[], int size)
{
	Stack stack000;
	Queue Qqueue;

	int peek = 0;

	for (int i = 0; i < size; i++)
	{
		if (Array[i] == 0)
		{
			while (!Qqueue.isEmpty())
			{
				NewArr[peek] = Qqueue.front();
				Qqueue.dequeue();
				peek++;
			}
			while (!stack000.isEmpty())
			{
				NewArr[peek] = stack000.top();
				stack000.pop();
				peek++;
			}
		}
		else if (Array[i] > 0)
		{
			stack000.push(Array[i]);
		}
		else if (Array[i] < 0)
		{
			Qqueue.enqueue(Array[i]);
		}
	}
	while (!stack000.isEmpty())
	{
		NewArr[peek] = stack000.top();
		stack000.pop();
		peek++;
	}
	while (!Qqueue.isEmpty())
	{
		NewArr[peek] = Qqueue.front();
		Qqueue.dequeue();
		peek++;
	}

	NewArr[peek] = 0;
}

bool Compare(int Num1, int Num2)
{
	return Num1 > Num2;
}

int main()
{
	const int SIZE = 18;
	int array[] = {-3, 2, -1, 5, 1, -4, 0, 11, 12, 13, -11, -12, 0, -1, -2, 6, 8, 7};
	int newArray[SIZE] = {0};

	std::cout << "*Array:          ";
	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	Assign(newArray, array, SIZE);
	std::cout << "*NewArray:       ";
	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << newArray[i] << " ";
	}
	std::cout << std::endl;

	sort(newArray, newArray + SIZE, Compare);
	std::cout << "*NewArray sorted: ";
	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << newArray[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}