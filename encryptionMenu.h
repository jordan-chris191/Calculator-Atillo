#pragma once
#include "Libs.h"
#include "RSA.h"
#include "DiffieHellman.h"

void EncryptionMenu()
{
	int encryptchoice;

	do {
		system("cls");
		cout << "1. RSA Encyrption\n";
		cout << "2. Ceasar/Shift Cipher Encryption\n";
		cout << "3. Diffie Hellman Encryption\n";
		cout << "4. AES Encryption\n";
		cout << "0. Exit\n";
		cout << "Enter the number of you choice: "; cin >> encryptchoice;

		switch (encryptchoice)
		{
			case 1:
				RSA();
			break;
			
			case 2:
				cout << "wala pa";
			break;

			case 3:
				DH();
			break;

			case 4:
				cout << "Wala pa";
			break;
			default:
			break;

		}

	} while (encryptchoice != 0);
}