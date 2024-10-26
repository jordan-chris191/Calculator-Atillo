#pragma once
#include <cstdlib>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
using namespace std;

#define ll long long;

bool isValidBinary(const string& str) {
	for (char ch : str) {
		if (ch != '0' && ch != '1' && ch != '.') {
			return false;
		}
	}
	return true;
}

bool isValidOctal(const string& str) {
	for (char ch : str) {
		if ((ch < '0' || ch > '7') && ch != '.') {
			return false;
		}
	}
	return true;
}

void binaryToDecimal(string binary) {
	int pointPos = binary.find('.');

	// Split the binary number into integer and fractional parts
	string integerPart = (pointPos == string::npos) ? binary : binary.substr(0, pointPos);
	string fractionalPart = (pointPos == string::npos) ? "" : binary.substr(pointPos + 1);

	long long decimalValue = 0;
	long long fractionalValue = 0.0;

	// Convert integer part
	cout << "________________________________________________________________________________________________________________________\n";
	cout << "\nInteger part solution steps: ";
	for (int i = integerPart.length() - 1; i >= 0; i--) {
		int indexFromRight = integerPart.length() - 1 - i;

		if (integerPart[i] == '1') {
			cout << "2^" << indexFromRight << " + " << decimalValue << " = ";
			decimalValue += pow(2, indexFromRight);
			cout << decimalValue;

			if (i != 0 || !fractionalPart.empty()) {
				cout << ", ";
			}
		}
	}

	// Convert fractional part
	cout << "\n\nFractional part solution steps: ";
	for (int i = 0; i < fractionalPart.length(); i++) {
		if (fractionalPart[i] == '1') {
			long long powerOfTwo = pow(2, -(long long)(i + 1));
			cout << "2^-" << (i + 1) << " + " << fractionalValue << " = ";
			fractionalValue += powerOfTwo;
			cout << fractionalValue;

			if (i != fractionalPart.length() - 1) {
				cout << ", ";
			}
		}
	}

	// Combine integer and fractional parts
	cout << endl << "\nDecimal equivalent: " << decimalValue + fractionalValue << endl;
	cout << "________________________________________________________________________________________________________________________\n";
}

void binaryToOctal(string binary) {
	int pointPos = binary.find('.');

	// Split the binary number into integer and fractional parts
	string integerPart = (pointPos == string::npos) ? binary : binary.substr(0, pointPos);
	string fractionalPart = (pointPos == string::npos) ? "" : binary.substr(pointPos + 1);

	// Pad the integer part
	long long intLength = integerPart.length();
	while (intLength % 3 != 0) {
		integerPart = '0' + integerPart;
		intLength++;
	}

	// Pad the fractional part
	long long fracLength = fractionalPart.length();
	while (fracLength % 3 != 0) {
		fractionalPart += '0';
		fracLength++;
	}

	// Convert integer part to octal
	cout << "________________________________________________________________________________________________________________________\n";
	cout << "\nInteger part solution steps: ";
	string octalIntegerPart;
	for (int i = 0; i < integerPart.length(); i += 3) {
		string triplet = integerPart.substr(i, 3);
		long long value = stoi(triplet, nullptr, 2);  // Convert triplet to decimal
		octalIntegerPart += to_string(value);  // Append to octal result
		cout << triplet << " (binary) = " << value << " (octal)";
		if (i + 3 < integerPart.length()) {
			cout << ", ";
		}
	}

	// Convert fractional part to octal
	cout << "\n\nFractional part solution steps: ";
	string octalFractionalPart;
	for (int i = 0; i < fractionalPart.length(); i += 3) {
		string triplet = fractionalPart.substr(i, 3);
		long long value = stoi(triplet, nullptr, 2);  // Convert triplet to decimal
		octalFractionalPart += to_string(value);  // Append to octal result
		cout << triplet << " (binary) = " << value << " (octal)";
		if (i + 3 < fractionalPart.length()) {
			cout << ", ";
		}
	}

	// Combine integer and fractional parts
	string octal = octalIntegerPart + (octalFractionalPart.empty() ? "" : "." + octalFractionalPart);
	cout << endl << "\nOctal equivalent: " << octal << endl;
	cout << "________________________________________________________________________________________________________________________\n";
}

void binaryToHexadecimal(string binary) {
	int pointPos = binary.find('.');

	// Split the binary number into integer and fractional parts
	string integerPart = (pointPos == string::npos) ? binary : binary.substr(0, pointPos);
	string fractionalPart = (pointPos == string::npos) ? "" : binary.substr(pointPos + 1);

	// Pad the integer part
	int intLength = integerPart.length();
	while (intLength % 4 != 0) {
		integerPart = '0' + integerPart;
		intLength++;
	}

	// Pad the fractional part
	long long fracLength = fractionalPart.length();
	while (fracLength % 4 != 0) {
		fractionalPart += '0';
		fracLength++;
	}


	cout << "________________________________________________________________________________________________________________________\n";
	cout << "\nInteger part solution steps: ";
	string hexadecimalIntegerPart;
	for (int i = 0; i < integerPart.length(); i += 4) {
		string quartet = integerPart.substr(i, 4);
		int value = stoi(quartet, nullptr, 2);
		stringstream ss;
		ss << hex << uppercase << value;
		hexadecimalIntegerPart += ss.str();
		cout << quartet << " (binary) = " << ss.str() << " (hex)";
		if (i + 4 < integerPart.length()) {
			cout << ", ";
		}
	}


	cout << "\n\nFractional part solution steps: ";
	string hexadecimalFractionalPart;
	for (int i = 0; i < fractionalPart.length(); i += 4) {
		string quartet = fractionalPart.substr(i, 4);
		int value = stoi(quartet, nullptr, 2);
		stringstream ss;
		ss << hex << uppercase << value;
		hexadecimalFractionalPart += ss.str();
		cout << quartet << " (binary) = " << ss.str() << " (hex)";
		if (i + 4 < fractionalPart.length()) {
			cout << ", ";
		}
	}

	// Combine integer and fractional parts
	string hexadecimal = hexadecimalIntegerPart + (hexadecimalFractionalPart.empty() ? "" : "." + hexadecimalFractionalPart);
	cout << endl << "\nHexadecimal equivalent: " << hexadecimal << endl;
	cout << "________________________________________________________________________________________________________________________\n";
}

void octalToBinary(const string& octal) {
	unordered_map<char, string> octalToBinaryMap = {
		{'0', "000"}, {'1', "001"}, {'2', "010"}, {'3', "011"},
		{'4', "100"}, {'5', "101"}, {'6', "110"}, {'7', "111"}
	};

	int pointPos = octal.find('.');
	string integerPart = (pointPos == string::npos) ? octal : octal.substr(0, pointPos);
	string fractionalPart = (pointPos == string::npos) ? "" : octal.substr(pointPos + 1);


	cout << "________________________________________________________________________________________________________________________\n";
	string binaryIntegerPart;
	cout << "\nInteger part solution steps: ";
	for (char digit : integerPart) {
		string binary = octalToBinaryMap[digit];
		binaryIntegerPart += binary;
		cout << digit << " (octal) = " << binary << " (binary)";
		if (digit != integerPart.back()) {
			cout << ", ";
		}
	}

	string binaryFractionalPart;
	cout << "\n\nFractional part solution steps: ";
	for (char digit : fractionalPart) {
		string binary = octalToBinaryMap[digit];
		binaryFractionalPart += binary;
		cout << digit << " (octal) = " << binary << " (binary)";
		if (digit != fractionalPart.back()) {
			cout << ", ";
		}
	}

	while (binaryIntegerPart.length() > 1 && binaryIntegerPart[0] == '0') {
		binaryIntegerPart.erase(0, 1);
	}

	string binary = binaryIntegerPart + (binaryFractionalPart.empty() ? "" : "." + binaryFractionalPart);
	cout << endl << "\nBinary equivalent: " << binary << endl;
	cout << "________________________________________________________________________________________________________________________\n";
}

double octalToDecimal(string octal)
{

	int point = octal.find('.');
	string intPart = point != string::npos ? octal.substr(0, point) : octal; // Integer part
	string fracPart = point != string::npos ? octal.substr(point + 1) : "";  // Fractional part

	int intDecValue = 0;
	double fracDecValue = 0.0;

	cout << "\nConverting integer part '" << intPart << "' from octal to decimal:" << endl;
	int base = 1; // Initializing base value to 1, i.e., 8^0
	for (int i = intPart.length() - 1; i >= 0; i--)
	{
		int last_digit = intPart[i] - '0'; // Convert char to int
		intDecValue += last_digit * base;
		cout << "Digit: " << last_digit << ", Base: " << base << ", Contribution to decimal: " << last_digit * base << endl;
		base = base * 8;
	}

	if (!fracPart.empty()) {
		cout << "\nConverting fractional part '" << fracPart << "' from octal to decimal:" << endl;
		double baseFrac = 1.0 / 8;
		for (int i = 0; i < fracPart.length(); i++)
		{
			int digit = fracPart[i] - '0'; // Convert char to int
			fracDecValue += digit * baseFrac;
			cout << "Digit: " << digit << ", Base: " << baseFrac << ", Contribution to decimal: " << digit * baseFrac << endl;
			baseFrac /= 8;
		}
	}

	double result = intDecValue + fracDecValue;
	cout << "\nFinal decimal value: " << intDecValue << " (integer part) + " << fracDecValue << " (fractional part) = " << result << endl;

	return result;
}

string decimalToHex(int dec) {
	string hex = "";
	while (dec > 0) {
		int remainder = dec % 16;
		if (remainder < 10) hex += (remainder + '0');
		else hex += (remainder - 10 + 'A');
		dec /= 16;
	}
	reverse(hex.begin(), hex.end());
	return hex.empty() ? "0" : hex;
}

string decimalFracToHex(double frac) {
	string hex = "";
	int precision = 5; 
	while (frac > 0 && precision--) {
		frac *= 16;
		int intPart = static_cast<int>(frac);
		if (intPart < 10) hex += (intPart + '0');
		else hex += (intPart - 10 + 'A');
		frac -= intPart;
	}
	return hex.empty() ? "0" : hex;
}

string octalToHexadecimal(string octal) {

	double decimalValue = octalToDecimal(octal);


	int intPart = static_cast<int>(decimalValue);
	double fracPart = decimalValue - intPart;


	string hexIntPart = decimalToHex(intPart);

	string hexFracPart = decimalFracToHex(fracPart);

	return hexFracPart.empty() ? hexIntPart : hexIntPart + "." + hexFracPart;
}

string decimaltoBinary()
{
	return 0;
}