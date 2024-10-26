#pragma once
#include <iostream>
#include "SOE.h"

void SOEMenu()
{
	int lower;
	int upper;

		system("cls");
		cout << "Sieve of Eratosthenes" << endl;
		cout << "Enter lower range: "; cin >> lower;
		cout << "Enter upper range: "; cin >> upper;
		system("cls");

		cout << "Sieve of Eratosthenes" << endl;
		cout << "Prime Numbers between " << lower << " and " << upper <<endl;
		SOE(lower, upper);

		cin.get();
		cin.ignore();
}