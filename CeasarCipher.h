#include "Libs.h"

string encrypt(string text, int shift) {
    string result = "";
    cout << "\n--- Encryption Process ---\n";
    cout << "Shift: " << shift << "\n";

    for (char c : text) {
        if (isalpha(c)) {
            char offset = isupper(c) ? 'A' : 'a';
            char encryptedChar = (c - offset + shift) % 26 + offset;
            result += encryptedChar;
            cout << "Original: " << c << " -> Encrypted: " << encryptedChar << endl;
        }
        else {
            result += c;
            cout << "Non-alphabet character remains unchanged: " << c << endl;
        }
    }
    return result;
}

string decrypt(string text, int shift) {
    string result = "";
    cout << "\n--- Decryption Process ---\n";
    cout << "Shift: " << shift << "\n";

    for (char c : text) {
        if (isalpha(c)) {
            char offset = isupper(c) ? 'A' : 'a';
            char decryptedChar = (c - offset - shift + 26) % 26 + offset;
            result += decryptedChar;
            cout << "Encrypted: " << c << " -> Decrypted: " << decryptedChar << endl;
        }
        else {
            result += c;
            cout << "Non-alphabet character remains unchanged: " << c << endl;
        }
    }
    return result;
}

void CC() 
{
    system("cls");
    string text;
    int shift;

    cin.ignore();
    cout << "Enter the message to encrypt: ";
    getline(cin,text);
    cout << "Enter the shift value: ";
    cin >> shift;

    string encryptedText = encrypt(text, shift);
    cout << "\nEncrypted Message: " << encryptedText << endl;

    string decryptedText = decrypt(encryptedText, shift);
    cout << "\nDecrypted Message: " << decryptedText << endl;

    cin.ignore();
    cin.get();
}