#pragma once
#include "Conversion.h"
#include "Libs.h"

void numberSystemConversionMenu() {
    int choice2;
    string binary, octal, hexadecimal;

    do {
        system("cls");
        cout << "Convert:\n";
        cout << "1. Binary\n";
        cout << "2. Octal\n";
        cout << "3. Decimal\n";
        cout << "4. Hexadecimal\n";
        cout << "0. Back\n";
        cout << "Enter your choice: ";
        cin >> choice2;

        switch (choice2) {
        case 1: // Binary Conversion
            system("cls");
            cout << "Enter Binary: ";
            cin >> binary;
            if (isValidBinary(binary)) {
                system("cls");
                cout << "Convert: " << binary << " binary\n";
                binaryToDecimal(binary);
                binaryToOctal(binary);
                binaryToHexadecimal(binary);
            }
            else {
                cout << "\nInvalid input. Please enter only '0' and '1'.\n";
            }
            cout << "\nPress Enter to return to the menu...";
            cin.ignore();
            cin.get();
            break;

        case 2: // Octal Conversion
            system("cls");
            cout << "Enter Octal: ";
            cin >> octal;
            if (isValidOctal(octal)) {
                system("cls");
                cout << "\nConvert: " << octal << " octal\n";
                octalToBinary(octal);
                cout << "\nDecimal equivalent: " << octalToDecimal(octal) << "\n";
                cout << "\nHexadecimal equivalent: " << octalToHexadecimal(octal) << "\n";
            }
            else {
                cout << "\nInvalid input. Please enter only digits containing 0-7.\n";
            }
            cout << "\nPress Enter to return to the menu...";
            cin.ignore();
            cin.get();
            break;

        case 3:
            system("cls");
            double decimal;
            cout << "Enter Decimal: ";
            cin >> decimal;
            if (decimal >= 0) {
                system("cls");
                cout << "\nConvert: " << decimal << " decimal\n";
                cout << "\nBinary equivalent: " << convertDecimalToBinary(decimal) << "\n";
                cout << "\nOctal equivalent: " << decimalToOctal(decimal) << "\n";
                cout << "\nHexadecimal equivalent: " << decimalToHex(decimal) << "\n";
            }
            else {
                cout << "\nInvalid input. Please enter a non-negative decimal value.\n";
            }
            cout << "\nPress Enter to return to the menu...";
            cin.ignore();
            cin.get();
            break;

        case 4:
            system("cls");
            cout << "Hexadecimal conversion not implemented yet.\n";
            cout << "\nPress Enter to return to the menu...";
            cin.ignore();
            cin.get();
            break;
        default:
            cout << "\nInvalid choice! Please select again.\n";
            break;
        }
    } while (choice2 != 0);
}