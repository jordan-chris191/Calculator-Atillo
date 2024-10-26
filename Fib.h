#pragma once
#include <iostream>
using namespace std;

int fib(int n)
{
	if (n <= 1)
	{
		return n;
	}


	return fib(n - 1) + fib(n - 2);
}

void display_fib(int n)
{

	cout << "Fibonacci Series: " << endl;
	for (int i = 0; i < n + 1; i++)
	{

		cout << "Fib" << "(" << i << ")" << " = " << fib(i);
		if (i > 1)
		{
			cout << " (" << fib(i - 1) << " + " << fib(i - 2) << ")";
		}
		cout << endl;
	}
}