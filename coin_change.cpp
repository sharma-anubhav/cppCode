// Non DP solution
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int coin_change(vector<int> &coins, int target)
{
    // base case
    if (target == 0)
    {
        return 0;
    }

    // recursive case
    int cur_min = INT_MAX - 1;
    for (auto x : coins)
    {
        if (target - x >= 0)
        {
            int local_min = 1 + coin_change(coins, target - x);
            if (local_min < cur_min)
            {
                cur_min = local_min;
            }
        }
    }
    return cur_min;
}

int main()
{
    vector<int> coins = {1, 3, 7, 10};
    int t = 15;
    cout << coin_change(coins, t);
}

/// DP solution
int coin_change(vector<int> &coins, int target, int dp[])
{
    // base case
    if (target == 0)
    {
        return 0;
    }
    if (dp[target] != INT_MAX)
    {
        return dp[target];
    }
    // recursive case
    int cur_min = INT_MAX - 1;
    for (auto x : coins)
    {
        if (target - x >= 0)
        {
            cur_min = min(cur_min, 1 + coin_change(coins, target - x, dp));
        }
    }
    return dp[target] = cur_min;
}

int main()
{
    vector<int> coins = {1, 3, 7, 10};
    int t = 15;
    int dp[t + 1];
    for (int i = 0; i <= t; i++)
    {
        dp[i] = INT_MAX;
    }
    cout << coin_change(coins, t, dp);
}
