#pragma once
#include "Libs.h"
#include "bitwiseOp.h"

void BitwiseMenu()
{
	int bitChoice;
	do {
		system("cls");
		cout << "1. AND\n";
		cout << "2. OR\n";
		cout << "3. XOR\n";
		cout << "4. NOT\n";
		cout << "5. Back\n";
		cout << "Enter the number of you choice: "; cin >> bitChoice;

		switch (bitChoice)
		{
		case 1:
			AND();
			cout << "\nPress Enter to return to the menu...";
			cin.ignore();
			cin.get();
			break;
		case 2:
			OR();
			cout << "\nPress Enter to return to the menu...";
			cin.ignore();
			cin.get();
			break;
		case 3:
			XOR();
			cout << "\nPress Enter to return to the menu...";
			cin.ignore();
			cin.get();
			break;
		case 4:
			system("cls");
			NOT();
			cout << "\nPress Enter to return to the menu...";
			cin.ignore();
			cin.get();
			break;
		default:
			break;
		}
	} while (bitChoice != 5);

}