/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <limits.h>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int merging_ropes(vector<int> ropes)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto x : ropes)
    {
        pq.push(x);
    }

    int cost = 0;
    while (!(pq.size() == 1))
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        cost = cost + a + b;
        pq.push(a + b);
    }
    return cost;
}

int main()
{

    vector<int> ropes{4, 3, 2, 6};

    cout << merging_ropes(ropes);
}
