#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int frongs_min_cost(int heights[], int i, int n, int dp[])
{
    // base case
    if (i == n - 1)
    {
        return 0;
    }

    if (dp[i] != INT_MAX)
    {
        return dp[i];
    }
    // recursive case
    int global_cost = INT_MAX;

    if (i + 1 <= n - 1)
    {
        global_cost = min(global_cost, abs(heights[i] - heights[i + 1]) + frongs_min_cost(heights, i + 1, n, dp));
    }
    if (i + 2 <= n - 1)
    {
        global_cost = min(global_cost, abs(heights[i] - heights[i + 2]) + frongs_min_cost(heights, i + 2, n, dp));
    }

    return dp[i] = global_cost;
}

int main()
{
    int heights[] = {30, 10, 60, 10, 60, 50};
    int len = sizeof(heights) / sizeof(int);
    int dp[len];
    for (int i = 0; i < len; i++)
    {
        dp[i] = INT_MAX;
    }
    cout << frongs_min_cost(heights, 0, len, dp);
}
