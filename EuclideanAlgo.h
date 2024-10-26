#pragma once
#include <iostream>
using namespace std;


int EuclideanAlgorithm(int a, int b)
{
	while (b != 0)
	{
		int result = a % b;
		a = b;
		b = result;
	}
	return a;
}