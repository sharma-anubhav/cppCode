
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// bad complexity recusrsive code without dp
int knapsack(int weights[], int prices[], int w, int n)
{

    // base case
    if (n == 0 or w == 0)
    {
        return 0;
    }

    // recursive case

    int take_value = 0;
    int not_value = 0;

    if (weights[n] <= w)
    {
        take_value = prices[n] + knapsack(weights, prices, w - weights[n], n - 1);
    }

    not_value = knapsack(weights, prices, w, n - 1);

    return max(take_value, not_value);
}

int main()
{
    int weights[] = {2, 7, 3, 4};
    int prices[] = {5, 20, 20, 10};
    int n = 4;
    int w = 11;

    cout << knapsack(weights, prices, w, n);
    return 0;
}