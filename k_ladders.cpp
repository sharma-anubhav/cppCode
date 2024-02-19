
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// non dp

int k_ladders(int n, int k)
{
    if (n < 0)
    {
        return 0;
    }
    else if (n == 0)
    {
        return 1;
    }
    else
    {
        int ans = 0;
        for (int i = 1; i <= k; i++)
        {
            ans = ans + k_ladders(n - i, k);
        }
        return ans;
    }
}

// DP solution

int k_ladders_dp(int n, int k, int dp[])
{
    if (n < 0)
    {
        return 0;
    }
    else if (n == 0)
    {
        return 1;
    }
    else
    {
        if (dp[n] != 0)
        {
            return dp[n];
        }
        int ans = 0;
        for (int i = 1; i <= k; i++)
        {
            ans = ans + k_ladders_dp(n - i, k, dp);
        }
        return dp[n] = ans;
    }
}

int main()
{
    int n, k;
    n = 4;
    k = 3;
    int dp[n + 1] = {0};
    cout << k_ladders_dp(n, k, dp);
}