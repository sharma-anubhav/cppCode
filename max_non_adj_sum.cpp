#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int max_non_adj_sum(int num[], int i, int n, int dp[])
{
    // base case
    if (i == n - 1)
    {
        return num[n - 1];
    }

    if (dp[i] != 0)
    {
        return dp[i];
    }
    // recursive case
    int global_sum = 0;

    if (i + 2 <= n - 1)
    {
        global_sum = max(global_sum, num[i] + max_non_adj_sum(num, i + 2, n, dp));
    }

    global_sum = max(global_sum, max_non_adj_sum(num, i + 1, n, dp));

    return dp[i] = global_sum;
}

int main()
{
    int num[] = {6, 10, 12, 7, 9, 14};
    int len = sizeof(num) / sizeof(int);
    int dp[len];
    for (int i = 0; i < len; i++)
    {
        dp[i] = 0;
    }
    cout << max_non_adj_sum(num, 0, len, dp);
}
