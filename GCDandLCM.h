#pragma once
#include <iostream>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

// Function to prime factorize a number
unordered_map<int, int> primeFactorize(int number) {
    unordered_map<int, int> factors;
    cout << "\nPrime factorization steps for " << number << ":\n";
    for (int i = 2; i <= number; i++) {
        while (number % i == 0) {
            factors[i]++;
            number /= i;
            cout << "Dividing by " << i << ", remaining quotient: " << number << "\n";
        }
        if (number == 1) break;
    }
    return factors;
}

// Function to find GCD using Prime Factorization
int gcdUsingPrimeFactorization(int a, int b) {
    unordered_map<int, int> factorsA = primeFactorize(a);
    unordered_map<int, int> factorsB = primeFactorize(b);

    cout << "\nPrime factors of " << a << ": ";
    for (const auto& factor : factorsA) {
        cout << factor.first << "^" << factor.second << " ";
    }
    cout << "\nPrime factors of " << b << ": ";
    for (const auto& factor : factorsB) {
        cout << factor.first << "^" << factor.second << " ";
    }
    cout << "\n\nFinding common prime factors with minimum exponents:\n";

    int gcd = 1;

    for (const auto& factor : factorsA) {
        int prime = factor.first;
        int countA = factor.second;

        if (factorsB.find(prime) != factorsB.end()) {
            int countB = factorsB[prime];
            int minCount = min(countA, countB);
            gcd *= pow(prime, minCount);
            cout << "Prime: " << prime << ", Exponents: min(" << countA << ", " << countB << ") = " << minCount
                << " -> Contribution to GCD: " << prime << "^" << minCount << "\n";
        }
    }

    return gcd;
}

// Function to find LCM using Prime Factorization
int lcmUsingPrimeFactorization(int a, int b) {
    unordered_map<int, int> factorsA = primeFactorize(a);
    unordered_map<int, int> factorsB = primeFactorize(b);

    cout << "\nPrime factors of " << a << ": ";
    for (const auto& factor : factorsA) {
        cout << factor.first << "^" << factor.second << " ";
    }
    cout << "\nPrime factors of " << b << ": ";
    for (const auto& factor : factorsB) {
        cout << factor.first << "^" << factor.second << " ";
    }
    cout << "\n\nCalculating LCM by taking maximum exponents of common prime factors:\n";

    int lcm = 1;

    // Combine factors from both factorizations, taking the highest exponent for each prime
    for (const auto& factor : factorsA) {
        int prime = factor.first;
        int countA = factor.second;
        int countB = factorsB[prime];  // If prime is not in factorsB, countB will be 0 by default
        int maxCount = max(countA, countB);
        lcm *= pow(prime, maxCount);
        cout << "Prime: " << prime << ", Exponent: max(" << countA << ", " << countB << ") = " << maxCount
            << " -> Contribution to LCM: " << prime << "^" << maxCount << "\n";
    }

    // Include any prime factors that are only in factorsB
    for (const auto& factor : factorsB) {
        if (factorsA.find(factor.first) == factorsA.end()) {
            int prime = factor.first;
            int countB = factor.second;
            lcm *= pow(prime, countB);
            cout << "Prime: " << prime << ", Exponent: " << countB << " (only in second number)"
                << " -> Contribution to LCM: " << prime << "^" << countB << "\n";
        }
    }

    return lcm;
}

void FindGCDAndLCMMenu() {
    int num1, num2, choice;
    do {
        system("cls");
        cout << "Choose Operation:\n";
        cout << "1. GCD Using Prime Factorization\n";
        cout << "2. LCM Using Prime Factorization\n";
        cout << "Enter your choice: ";
        int method;
        cin >> method;

        cout << "Input the first number: ";
        cin >> num1;
        cout << "Input the second number: ";
        cin >> num2;

        switch (method) {
        case 1: {
            int gcd = gcdUsingPrimeFactorization(num1, num2);
            cout << "\nThe GCD of " << num1 << " and " << num2 << " is: " << gcd << endl;
            break;
        }
        case 2: {
            int lcm = lcmUsingPrimeFactorization(num1, num2);
            cout << "\nThe LCM of " << num1 << " and " << num2 << " is: " << lcm << endl;
            break;
        }
        default:
            cout << "Invalid choice. Please select either 1 or 2.\n";
        }

        cout << "\nPress 1 to calculate again or any other key to exit: ";
        cin >> choice;
    } while (choice == 1);
}
