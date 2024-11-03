#pragma once
#include "Libs.h"

int modExp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1; 
        base = (base * base) % mod; 
    }
    return result;
}

void DH() {
    system("cls");
    int Prime, G, Ap, Bp;

    cout << "Enter a prime number (P): ";
    cin >> Prime;
    cout << "Enter a generator (G): ";
    cin >> G;

    cout << "Enter private key of Alice (a): ";
    cin >> Ap;
    cout << "Enter private key of Bob (b): ";
    cin >> Bp;

    int publicAp = modExp(G, Ap, Prime);
    int publicBp = modExp(G, Bp, Prime);

    int SsecretofAp = modExp(publicBp, Ap, Prime);
    int SsecretofBp = modExp(publicAp, Bp, Prime);

    cout << "\n--- Diffie-Hellman Key Exchange Process ---" << endl;
    cout << "Public Key of Alice (A): " << publicAp << endl;
    cout << "Public Key of Bob (B): " << publicBp << endl;

    cout << "Alice calculates the shared secret:" << endl;
    cout << "SsecretofAp = B^a mod P = " << publicBp << "^" << Ap << " mod " << Prime << " = " << SsecretofAp << endl;

    cout << "Bob calculates the shared secret:" << endl;
    cout << "SsecretofBp = A^b mod P = " << publicAp << "^" << Bp << " mod " << Prime << " = " << SsecretofBp << endl;

    cout << "\nShared Secret of Alice: " << SsecretofAp << endl;
    cout << "Shared Secret of Bob: " << SsecretofBp << endl;
    cin.ignore();
    cin.get();
}
