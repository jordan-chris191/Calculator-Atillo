//#pragma once
//#include "Libs.h"
//#include "RecyclableMethods.h"
//
//class CaesarCipher : SieveOfErathosthenes
//{
//public:
//	void MAIN_LOOP()
//	{
//		string	inputYawa, encrypted, decrypted;
//		int		shiftVal = 0, choice = 0, input = -1, tryAgainFlag = -1;
//
//		while (tryAgainFlag == -1 || tryAgainFlag == 2)
//		{
//			cout << "*********CAESAR CIPHER*********" << endl;
//
//			encryptOrDecrypt(choice, shiftVal, inputYawa, encrypted, decrypted);
//
//			//CLEAR BUFFER //YAWA WALAY REGION SA C++
//			inputYawa.clear();
//			encrypted.clear();
//			decrypted.clear();
//			shiftVal = 0;
//			choice = 0;
//			input = -1;
//			tryAgainFlag = -1;
//			//CLEAR BUFFER
//
//			tryAgainFlag = -1;
//			SieveOfErathosthenes::EXIT_MENU_LOOP(tryAgainFlag, input);
//		}
//	}
//
//protected:
//	void encryptOrDecrypt(int choice, int shiftVal, string input, string& encrypted, string& decrypted)
//	{
//		while (choice > 2 || choice < 1 || cin.fail())
//		{
//			if (cin.fail())
//			{
//				cin.clear();
//				cin.ignore(numeric_limits<streamsize>::max(), '\n');
//			}
//
//			cout << "Encrypt or Decrypt? " << endl;
//			cout << "[ 1 ] Encrypt " << endl;
//			cout << "[ 2 ] Decrypt " << endl;
//			cout << "Input: "; cin >> choice;
//			newLineMaker(0);
//		}
//
//		cout << "Inputs:" << endl;
//		switch (choice)
//		{
//		case 1:
//			cout << "Input Text  : "; cin.ignore(numeric_limits<streamsize>::max(), '\n'); getline(cin, input); //CLEAR THE BUFFER FIRST
//			cout << "Shift Value : "; cin >> shiftVal;
//
//			encrypt(input, shiftVal, encrypted);
//
//			displayResultEncryption(encrypted, shiftVal);
//			break;
//
//		case 2:
//			cout << "Input Encrypted Text : "; cin.ignore(numeric_limits<streamsize>::max(), '\n'); getline(cin, input);
//			cout << "         Shift Value : "; cin >> shiftVal;
//
//			decrypt(input, shiftVal, decrypted);
//
//			displayResultDecryption(input, decrypted);
//			break;
//
//		default:
//			cout << "BRO READ THE INSTRUCTION (???)" << endl;
//			break;
//		}
//	}
//	void encrypt(string& input, int shift, string& encrypted)
//	{
//		for (int i = 0; i < input.size(); i++)
//		{
//			if (isupper(input[i]))
//			{
//				encrypted += (static_cast<int>(input[i]) - 'A' + shift) % 26 + 'A';
//			}
//			else if (islower(input[i]))
//			{
//				encrypted += (static_cast<int>(input[i]) - 'a' + shift) % 26 + 'a';
//			}
//			else
//			{
//				encrypted += input[i];
//			}
//		}
//	}
//	void decrypt(string& encrypted, int shift, string& decrypted)
//	{
//		for (int i = 0; i < encrypted.size(); i++)
//		{
//			if (isupper(encrypted[i]))
//			{
//				decrypted += (static_cast<int>(encrypted[i]) - 'A' - shift + 26) % 26 + 'A';
//			}
//			else if (islower(encrypted[i]))
//			{
//				decrypted += (static_cast<int>(encrypted[i]) - 'a' - shift + 26) % 26 + 'a';
//			}
//			else
//			{
//				decrypted += encrypted[i];
//			}
//		}
//	}
//
//	void displayResultEncryption(string& encrypted, int shift)
//	{
//		string decrypted;
//		decrypt(encrypted, shift, decrypted);
//
//		newLineMaker(0);
//		cout << "***************************" << endl;
//		cout << "Answer:" << endl;
//		cout << "Encrypted  :" << encrypted << endl;
//		cout << "Decrypted  :" << decrypted << endl;
//		cout << "***************************" << endl;
//	}
//	void displayResultDecryption(string input, string decrypted)
//	{
//		newLineMaker(0);
//		cout << "******************************************************" << endl;
//		cout << "Answer:" << endl;
//		cout << "Original Text (Encrypted) :" << input << endl;
//		cout << "                Decrypted :" << decrypted << endl;
//		cout << "******************************************************" << endl;
//	}
//};
