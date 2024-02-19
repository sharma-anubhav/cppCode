#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longest_increasing_subsequence(int num[], int n, int dp[])
{

    dp[0] = 1;
    int global_max = INT_MIN;

    for (int i = 1; i < n; i++)
    {

        int temp = -1;

        for (int j = 0; j < i; j++)
        {

            if (num[j] < num[i])
            {
                temp = j;
            }
        }

        if (temp != -1)
        {
            dp[i] = 1 + dp[temp];
            global_max = max(global_max, dp[i]);
        }
    }
    return global_max;
}

int main()
{
    int num[] = {50, 4, 10, 8, 30, 100};
    int len = sizeof(num) / sizeof(int);
    int dp[len];
    for (int i = 0; i < len; i++)
    {
        dp[i] = 1;
    }
    cout << longest_increasing_subsequence(num, len, dp);
}
