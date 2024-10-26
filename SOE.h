#pragma once
#include <iostream>
using namespace std;

bool prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void SOE(int lower, int upper) {
    int count = 0;
    
    for (int i = lower; i <= upper; i++) {

        if (prime(i)) 
        {
            cout << "[" << i << "]";
            count++;
            if (count % 10 == 0) 
            {
                cout << endl;
            }
        }
    }
}
