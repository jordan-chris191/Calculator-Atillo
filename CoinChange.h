#pragma once
#include <iostream>
#include <vector>
using namespace std;

int calc(int amount, vector<float>& coins, int i, vector<vector<float>>& dp)
{
    if (i < 0 || amount < 0)
        return 0;
    if (amount == 0)
        return 1;
    if (dp[i][amount] != -1)
        return dp[i][amount];
    return dp[i][amount] = calc(amount - coins[i], coins, i, dp) + calc(amount, coins, i - 1, dp);
}

int change(int amount, vector<float>& coins)
{
    vector<vector<float>>dp(301, vector<float>(5001, -1));
    return calc(amount, coins, coins.size() - 1, dp);
}

void coinchange()
{
    int amount = 6;
    vector <float> coins = { 1,5,3,2 };

    cout << "total possible combinations of change: " << change(amount, coins);
    cin.get();
    cin.ignore();
}