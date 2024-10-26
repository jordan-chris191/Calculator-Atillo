#pragma once
#include <iostream>
#include "Fib.h"

void FibMenu()
{

	int n;
	system("cls");
	cout << "Enter a number to start the fibonacci sequence: "; cout << "fib(n)"; cin >> n;
	display_fib(n);
	cin.get();
	cin.ignore();
}