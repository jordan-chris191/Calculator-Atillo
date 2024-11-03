#pragma once
#include "Libs.h"
#include "RSA.h"

void EncryptionMenu()
{
	int encryptchoice;

	do {
		system("cls");
		cout << "1. RSA Algorithm\n";
		cout << "2. Ceasar Cipher Algorithm\n";
		cout << "3. Diffie Hellman\n";
		cout << "4. MD5";
		cout << "5. SHA-1";
		cout << "6. Exit\n";
		cout << "Enter the number of you choice: "; cin >> encryptchoice;

		switch (encryptchoice)
		{
			case 1:
				RSA();
			break;

			case 2:
				cout << "Not finish yet";
			break;

			case 3:
				cout << "Not finish yet";
			break;

			case 4:
				cout << "Not finish yet";
			break;

			case 5:
				cout << "Not finish yet";
			break;

			default:
			break;

		}

	} while (encryptchoice != 6);





}