/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int min_arr_jump(int jumps[], int n, int i, int dp[])
{
    // base case
    if (i == n - 1)
    {
        return 0;
    }

    // recursive case
    int max_jump = jumps[i];
    int global_count = INT_MAX;
    if (dp[i] != INT_MAX)
    {
        return dp[i];
    }

    for (int j = 1; j <= max_jump; j++)
    {
        if (i + j <= n - 1)
        {
            global_count = min(global_count, 1 + min_arr_jump(jumps, n, i + j, dp));
        }
    }
    return dp[i] = global_count;
}

int main()
{
    int jumps[] = {3, 4, 2, 1, 2, 3, 10, 1, 1, 1, 2, 5};
    int len = sizeof(jumps) / sizeof(int);
    int dp[len];
    for (int i = 0; i < len; i++)
    {
        dp[i] = INT_MAX;
    }
    cout << min_arr_jump(jumps, len, 0, dp);
}
