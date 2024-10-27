#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void PrimeFactor()
{
    int factor;
    cout << "Prime Factorization Long Division Method" << endl;
    cout << "Input a number to factor: "; cin >> factor;

    if (is_prime(factor)) {
        cout << "The factors of: " << factor << " is" << endl;
        cout << factor << "*1" << endl;
    }

    vector<int> possible_factor;
    int original = factor;

    for (int i = 2; i <= factor; i++) {
        while (factor % i == 0) {
            possible_factor.push_back(i);
            factor /= i;
        }
        if (factor == 1) break;
    }

    cout << "The factors of " << original << ": ";
    for (int i = 0; i < possible_factor.size(); i++) {
        cout << possible_factor[i];
        if (i < possible_factor.size() - 1) {
            cout << "*";
        }
    }

    unordered_map<int, int> countMap;


    for (int num : possible_factor) {
        countMap[num]++;
    }

    bool first = true;
    cout << " or ";
    for (const auto& pair : countMap)
    {
        if (!first)
        {
            cout << "*";
        }

        if (pair.second > 1)
        {

            cout << pair.first << "^" << pair.second;

        }
        else
        {
            cout << pair.first;
        }
        first = false;
    }

}
