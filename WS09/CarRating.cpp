
// Junayad Bin Forhad
// 160158218
// 06/08/2022

#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <forward_list>
using namespace std;
struct CarRating
{
	std::string name;
	std::string country;
	double reliability;
	double fuelEfficiency;
	double horsePower;
};

void PrintReliable(CarRating kar)
{
	cout << kar.name << ", " << kar.country << ", reliability: " << kar.reliability << endl;
}

bool SortReliablity(CarRating kar1, CarRating kar2)
{
	return (kar1.reliability > kar2.reliability);
}

void PrintFuelEfficient(CarRating kar)
{
	cout << kar.name << ", " << kar.country << ", fuel efficiency: " << kar.fuelEfficiency << endl;
}
bool SortFuelEfficiency(CarRating kar1, CarRating kar2)
{
	return (kar1.fuelEfficiency < kar2.fuelEfficiency);
}

bool SortHP(CarRating kar1, CarRating kar2)
{
	return (kar1.horsePower > kar2.horsePower);
}

void PrintHP(CarRating kar)
{
	cout << kar.name << ", " << kar.country << ", Horse power: " << kar.horsePower << endl;
}

int MathHP(int sum, CarRating kar)
{
	if (kar.country == "Germany")
		return sum + kar.horsePower;
	else
		return sum;
}

void HighReliability(CarRating kar)
{
	if (kar.reliability >= 8.0)
		cout << kar.name << ", " << kar.country << ", reliability: " << kar.reliability << endl;
}

int German(int count, CarRating kar)
{
	if (kar.country == "Germany")
		return count + 1;
	else
		return count;
}

CarRating CUSA(CarRating kar)
{
	if (kar.country == "USA")
	{
		kar.country = "United States";
		return kar;
	}
	else
		return kar;
}

bool SortRating(CarRating kar1, CarRating kar2)
{
	double rating1 = 2.0 * (kar2.reliability - 4.1) + 2.0 * (12.1 - kar2.fuelEfficiency) + (kar2.horsePower - 130.0) / 37.0;
	double rating2 = 2.0 * (kar1.reliability - 4.1) + 2.0 * (12.1 - kar1.fuelEfficiency) + (kar1.horsePower - 130.0) / 37.0;
	return (rating1 < rating2);
}

void process_Cars(vector<CarRating> &kar)
{
	// Task 1 - Sort and print out all cars in order of their reliability rating (higher is better).

	cout << "Sorted by reliability: " << endl;
	{
		// http://www.cplusplus.com/reference/algorithm/sort/ //for sorting
		sort(kar.begin(), kar.end(), SortReliablity);

		// http://www.cplusplus.com/reference/algorithm/for_each/ //for printing
		for_each(kar.begin(), kar.end(), PrintReliable);
	}

	// Task 2 - Sort and print out all cars in order of their fuel efficiency (lower is better).
	cout << "\nSorted by fuel efficiency: " << endl;
	{
		sort(kar.begin(), kar.end(), SortFuelEfficiency);
		for_each(kar.begin(), kar.end(), PrintFuelEfficient);
	}

	// Task 3 - Sort and print out all cars in order of their horse power (higher is better).
	cout << "\nSorted by horsepower: " << endl;
	{
		sort(kar.begin(), kar.end(), SortHP);
		for_each(kar.begin(), kar.end(), PrintHP);
	}

	// Task 4 - Print out the average horse power of all German cars.
	{
		// https://www.cplusplus.com/reference/numeric/accumulate/ //for summing
		double sum = 0;
		int count = 0;
		sum = accumulate(kar.begin(), kar.end(), sum, MathHP);
		count = accumulate(kar.begin(), kar.end(), count, German);
		cout << "\nThe average horse power of all German cars are: " << sum / count << endl;
	}

	// Task 5 - Print out all cars with reliability greater than (or equal to) 8.0.
	cout << "\nHigh reliability cars: " << endl;
	{
		for_each(kar.begin(), kar.end(), HighReliability);
	}

	// Task 6 - Change the country of all American cars from "USA" to "United States".
	{
		// http://www.cplusplus.com/reference/algorithm/transform/
		transform(kar.begin(), kar.end(), kar.begin(), CUSA);
	}

	// Task 7 - Reorganize the vector of all cars in order of their rating (higher is better) based on the formula:
	//  rating = 2.0*(reliability-4.1) + 2.0*(12.1-fuelEfficiency) + (horsePower-130.0)/37.0
	{
		sort(kar.begin(), kar.end(), SortRating);
	}
}

int main()
{
	vector<CarRating> car({{"Toyota Corolla", "Japan", 9.1, 8.0, 130.0},
						   {"Honda Civic", "Japan", 8.8, 7.8, 138.0},
						   {"Dodge Charger", "USA", 6.5, 10.8, 300.0},
						   {"BMW 330x", "Germany", 7.2, 8.9, 260.0},
						   {"Chevrolet Impala", "USA", 8.1, 9.9, 280.0},
						   {"BMW 240", "Germany", 7.4, 9.2, 320.0},
						   {"Ford Fusion", "USA", 6.8, 9.7, 210.0},
						   {"Subaru Impreza", "Japan", 7.9, 8.5, 150.0},
						   {"BMW M5", "Germany", 6.9, 12.1, 500.0},
						   {"Toyota Camry Hybrid", "Japan", 9.3, 7.0, 205.0},
						   {"Audi A4", "Germany", 8.9, 8.8, 255.0},
						   {"Dodge P.O.S.", "USA", 4.1, 11.7, 233.0}});
	cout << "LIST OF CARS:" << endl;
	for_each(car.begin(), car.end(), [](const CarRating &c)
			 { cout << c.name << ", " << c.country << "." << endl; });
	cout << endl;
	process_Cars(car);
	cout << endl;
	cout << "LIST OF CARS ORDERED BY RATING:" << endl;
	for_each(car.begin(), car.end(), [](const CarRating &c)
			 { cout << c.name << ", " << c.country << "." << endl; });
	return 0;
}