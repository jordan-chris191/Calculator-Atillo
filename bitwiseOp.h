#pragma once
#include "Libs.h"

using namespace std;

bool validBinary(const string& str) {
	for (char ch : str) {
		if (ch != '0' && ch != '1' && ch != '.') {
			return false;
		}
	}
	return true;
}

void AND()
{
	system("cls");
	string bin1;
	string bin2;

	cout << "AND Operator" << endl;
	cout << "Enter 1st Binary: "; cin >> bin1;
	cout << "Enter 2nd Binary: "; cin >> bin2;


	if (validBinary(bin1) && validBinary(bin2))
	{

		if (bin1.length() > bin2.length())
		{
			int newlength = bin1.length() - bin2.length();
			string newbin2;
			for (int i = 0; i < newlength; i++)
			{
				newbin2 += "0";
			}
			bin2 = newbin2 + bin2;
		}
		else if (bin1.length() < bin2.length())
		{
			int newlength = bin2.length() - bin1.length();
			string newbin1;
			for (int i = 0; i < newlength; i++)
			{
				newbin1 += "0";
			}
			bin1 = newbin1 + bin1;
		}
		cout << endl;
		cout << "    " << bin1 << endl;
		for (int i = 0; i < bin1.length(); i++)
		{
			if (bin1[i] == '1' && bin2[i] == '1')
			{
				bin1[i] = '1';
			}
			else
			{
				bin1[i] = '0';
			}
		}
		
		string line;
		for (int i = 0; i < bin1.length(); i++)
		{
			line += "-";
		}
		
		cout << "AND " << bin2 << endl;
		cout << "----" << line << endl;
		cout << "    " << bin1;
	}
	else
	{
		cout << "Input a valid binary number";
	}
	
}

void OR()
{
	system("cls");
	string bin1;
	string bin2;

	cout << "OR Operator" << endl;
	cout << "Enter 1st Binary: "; cin >> bin1;
	cout << "Enter 2nd Binary: "; cin >> bin2;
	if (validBinary(bin1) && validBinary(bin2))
	{
		if (bin1.length() > bin2.length())
		{
			int newlength = bin1.length() - bin2.length();
			string newbin2;
			for (int i = 0; i < newlength; i++)
			{
				newbin2 += "0";
			}
			bin2 = newbin2 + bin2;
		}
		else if (bin1.length() < bin2.length())
		{
			int newlength = bin2.length() - bin1.length();
			string newbin1;
			for (int i = 0; i < newlength; i++)
			{
				newbin1 += "0";
			}
			bin1 = newbin1 + bin1;
		}

		cout << endl;
		cout << "   " << bin1 << endl;

		for (int i = 0; i < bin1.length(); i++)
		{
			if (bin1[i] == '1' || bin2[i] == '1')
			{
				bin1[i] = '1';
			}
			else
			{
				bin1[i] = '0';
			}
		}
		string line;
		for (int i = 0; i < bin1.length(); i++)
		{
			line += "-";
		}
	
		cout << "OR " << bin2 << endl;
		cout << "---" << line <<endl;
		cout << "   " <<bin1;
	}
	else
	{
		cout << "Input a valid binary number";
	}

}

void XOR()
{
	system("cls");
	string bin1;
	string bin2;

	cout << "XOR Operator" << endl;
	cout << "Enter Binary 1: "; cin >> bin1;
	cout << "Enter Binary 2: "; cin >> bin2;


	if (validBinary(bin1) && validBinary(bin2))
	{

		if (bin1.length() > bin2.length())
		{
			int newlength = bin1.length() - bin2.length();
			string newbin2;
			for (int i = 0; i < newlength; i++)
			{
				newbin2 += "0";
			}
			bin2 = newbin2 + bin2;
		}
		else if (bin1.length() < bin2.length())
		{
			int newlength = bin2.length() - bin1.length();
			string newbin1;
			for (int i = 0; i < newlength; i++)
			{
				newbin1 += "0";
			}
			bin1 = newbin1 + bin1;
		}
		cout << endl;
		cout << "    " << bin1 << endl;
		for (int i = 0; i < bin1.length(); i++)
		{
			if (bin1[i] == '1' && bin2[i] == '1' )
			{
				bin1[i] = '0';
			}
			else if (bin1[i] == '0' && bin2[i] == '0')
			{
				bin1[i] = '0';
			}
			else
			{
				bin1[i] = '1';
			}
		}
	
		string line;

		for (int i = 0; i < bin1.length(); i++)
		{
			line += "-";
		}

		cout << "XOR " << bin2 << endl;
		cout << "----" << line << endl;
		cout << "    " << bin1;
		
	}
	else
	{
		cout << "Input a valid binary number";
	}
}

void NOT()
{
	system("cls");
	string bin;
	cout << "NOT Operator"<<endl;
	cout << "Enter Binary: "; cin >> bin;
	cout << endl;
	cout <<"   " << bin << endl;
	if (validBinary(bin))
	{
		for (int i = 0; i < bin.length(); i++)
		{
			if (bin[i] == '0')
			{
				bin[i] = '1';
			}
			else
			{
				bin[i] = '0';
			}
		}
		
		string line;
		for (int i = 0; i < bin.length(); i++)
		{
			line += "-";
		}
		cout <<  "NOT" << line << endl;
		cout <<  "   " << bin;
	}
	else
	{
		cout << "Input a valid binary number";
	}
}