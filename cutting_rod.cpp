// non DP
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int cutting_rod(int prices[], int len, int dp[])
{
    if (len == 0)
    {
        return 0;
    }

    // recursive case
    int cur_profit = 0;
    for (int i = 0; i < len; i++)
    {
        if (len - i - 1 >= 0)
        {
            cur_profit = max(cur_profit, prices[i] + cutting_rod(prices, len - i - 1, dp));
        }
    }

    return cur_profit;
}

int main()
{
    int prices[] = {3, 5, 8, 9, 10, 17, 17, 20};
    int len = 8;
    int dp[len + 1];
    for (int i = 0; i <= len; i++)
    {
        dp[i] = 0;
    }
    cout << cutting_rod(prices, len, dp);
}

// DP
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int cutting_rod(int prices[], int len, int dp[])
{
    if (len == 0)
    {
        return 0;
    }

    // recursive case
    if (dp[len] != 0)
    {
        return dp[len];
    }
    int cur_profit = 0;
    for (int i = 0; i < len; i++)
    {
        if (len - i - 1 >= 0)
        {
            cur_profit = max(cur_profit, prices[i] + cutting_rod(prices, len - i - 1, dp));
        }
    }

    return dp[len] = cur_profit;
}

int main()
{
    int prices[] = {3, 5, 8, 9, 10, 17, 17, 20};
    int len = 8;
    int dp[len + 1];
    for (int i = 0; i <= len; i++)
    {
        dp[i] = 0;
    }
    cout << cutting_rod(prices, len, dp);
}
