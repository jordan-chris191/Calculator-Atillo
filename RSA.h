#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int coprime_e(int phi_n) {
    srand(time(NULL));
    int a;
    do {
        a = 1 + (rand() % (phi_n - 1));
    } while (gcd(a, phi_n) != 1);
    return a;
}
int extended_gcd(int e, int phiN, int& x, int& y) {
    if (e == 0) {
        x = 0;
        y = 1;
        return phiN;
    }

    int x1, y1;
    int gcd = extended_gcd(phiN % e, e, x1, y1);

    x = y1 - (phiN / e) * x1;
    y = x1;

    return gcd;
}
int generate_d(int e, int phiN) {
    int x, y;
    int gcd = extended_gcd(e, phiN, x, y);

    if (gcd != 1) {
        cerr << "No modular inverse exists for the given e and phiN!" << endl;
        return -1;
    }

    int d = (x % phiN + phiN) % phiN;

    return d;
}
int mod_exp(int base, int exp, int mod) {
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
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
int generate_random_prime(int lower, int upper) {
    int prime;
    do {
        prime = lower + (rand() % (upper - lower));
    } while (!is_prime(prime));
    return prime;
}

void RSA() 
{
    system("cls");
    srand(time(NULL));
    int lower_bound = 1;
    int upper_bound = 50;
    int p = generate_random_prime(lower_bound, upper_bound);
    int q = generate_random_prime(lower_bound, upper_bound);
    int n = p * q;
    int phi_n = (p - 1) * (q - 1);
    int e = coprime_e(phi_n);
    int d = generate_d(e, phi_n);
    int m;

    do
    {
        cout << "Enter a message (plain text) to encrypt (must be less than n = " << n << "): ";
        cin >> m;
        cout << endl;

        if (m >= n) {
            system("cls");
            cerr << "Message must be less than n! Try Again." << endl;
        }
    } while (m >= n);
   

    cout << "p = " << p << " and q = " << q << endl << endl;
    cout << "Step 1. Compute n = p * q = " << p << " * " << q << " = " << n << endl << endl;
    cout << "Step 2. Compute tot(n) = (p - 1) * (q - 1) = " << p - 1 << " * " << q - 1 << " = " << phi_n << endl << endl;
    cout << "Step 3. Choose e such that 1 < e < tot(n) and e and tot(n) are coprime. Let e = " << e << endl << endl;
    cout << "Step 4. Compute d such that (d * e) % tot(n) = 1. One solution is d = " << d << " [(" << d << " * " << e << ") % " << phi_n << " = 1]" << endl << endl;
    cout << "Public Key (e, n) => (" << e << ", " << n << ")" << endl << endl;
    cout << "Private Key (d, n) => (" << d << ", " << n << ")" << endl << endl;


    int c = mod_exp(m, e, n);
    cout << "The encryption of plain text = " << m << " is equal to cipher text = " << m << "^" << e << " % " << n << " = " << c << endl << endl;

    int decrypted_m = mod_exp(c, d, n);
    cout << "The decryption of cipher text = " << c << " is equal to plain text = " << c << "^" << d << " % " << n << " = " << decrypted_m << endl;

    cout << "\nPress Enter to return to the menu...";
    cin.ignore();
    cin.get();
}