#include "MainMenu.h"
#include "ConversionMenu.h"
#include "MdasMenu.h"
#include "BitwiseMenu.h"
#include "EncryptionMenu.h"
#include "FibMenu.h"
#include "SOEMenu.h"
#include "GCDandLCM.h"
#include "GreedyAlgorithms.h"

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
			  FindGCDAndLCMMenu();
			  break;	
		  case 5:
			  FibMenu();
			  break;
		  case 6:
			  //ModArithmeticMenu();
			  break;
		  case 7:
			  SOEMenu();
			  break;
		  case 8:
			  EncryptionMenu();
			  break;
		  case 9:
			  GreedyAlgoMenu();
			  break;
		  default:
			  break;
		}
	} while (choice1 != 0);
	system("cls");
	cout << "Bye :)";
}