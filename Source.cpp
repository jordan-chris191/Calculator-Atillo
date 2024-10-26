#include <iostream>
#include "mainMenu.h"
#include "conversionMenu.h"
#include "mdasMenu.h"
#include "bitwiseMenu.h"
#include "EuclideanMenu.h"
#include "encryptionMenu.h"
#include "FibMenu.h"
#include "SOEMenu.h"
using namespace std;

int main()
{
	int choice1;
	do
	{
		system("cls");
		mainMenu();
		cin >> choice1;

		switch (choice1)
		{
		  case 1: 
			   numberSystemConversionMenu();
			   break;
		  case 2:
			  //MDASmenu();
			  break;
		  case 3:
			  BitwiseMenu();
			  break;
		  case 4:
			  //PrimeFactorMenu();
			  break;
		  case 5:
			  //EgyptianFracMenu();
			  break;
		  case 6:
			  FibMenu();
			  break;
		  case 7:
			  //ModularMenu();
			  break;
		  case 8:
			  EuclideanMenu();
			  break;
		  case 9:
			  SOEMenu();
			  break;
		  case 10:
			  EncryptionMenu();
			  break;
		  case 11:
			  //GreedyAlgoMenu();
			  break;
		  default:
			  break;
		}
	} while (choice1 != 12);
	system("cls");
	cout << "Bye :)";
}