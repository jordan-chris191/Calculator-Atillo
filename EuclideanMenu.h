#pragma once
#include <iostream>
#include "EuclideanAlgo.h"
using namespace std;


void EuclideanMenu()
{
	system("cls");
	int i = 0;
	int choiceEuclid;
	int a, b;

	do
	{
		cout << "Find the gcd" << endl;
		cout << "Enter a: "; cin >> a;
		cout << "Enter b: "; cin >> b;
		cout << endl;
		system("cls");
		cout << "Solution Steps :" << endl;
		cout << "gcd(" << a << "," << b << ")" <<endl;
		
		while (b != 0)
		{
			int result = a % b;
			cout << "a: " << a << " b: " << b << " = " << result << endl;
		
			a = b;
			b = result;

		}
			
		cout << "gcd: " << EuclideanAlgorithm(a,b) << endl;
		cout << endl;
		cout << "Again?(Press 1 to exit and any number to continue): "; cin >> choiceEuclid;
	} while (choiceEuclid != 1);
};