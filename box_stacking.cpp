/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool compare_box(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int box_stacking(vector<vector<int>> boxes, int dp[])
{
    int l = boxes.size();
    int max_h = dp[0];
    for (int i = 0; i < l; i++)
    {
        int global_max = 0;
        for (int j = 0; j < i; j++)
        {
            if (boxes[j][0] < boxes[i][0] and boxes[j][1] < boxes[i][1])
            {
                global_max = max(global_max, dp[j]);
            }
        }
        dp[i] = global_max + dp[i];
        max_h = max(max_h, dp[i]);
    }
    return max_h;
}

int main()
{
    vector<vector<int>> boxes{{2, 1, 2}, {3, 2, 3}, {2, 2, 8}, {2, 3, 4}, {2, 2, 1}, {4, 4, 5}};
    sort(boxes.begin(), boxes.end(), compare_box);

    int n = boxes.size();
    int dp[n];

    for (int i = 0; i < n; i++)
    {
        dp[i] = boxes[i][2];
    }

    cout << box_stacking(boxes, dp);

    return 0;
}

// 2 2 8 --
// 4 4 5
// 2 3 4
// 3 2 3
// 2 1 2
// 2 2 1