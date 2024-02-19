#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

void min_pair(vector<int> a, vector<int> b)
{
    sort(b.begin(), b.end());
    int a_p;
    int b_p;
    int diff = INT_MAX;

    for (auto x : a)
    {

        auto temp = lower_bound(b.begin(), b.end(), x) - b.begin();

        if (temp >= 1 and b[temp - 1] - x < diff)
        {
            diff = b[temp - 1] - x;
            a_p = x;
            b_p = b[temp - 1];
        }
        if (temp != b.size() and b[temp] - x < diff)
        {
            diff = b[temp] - x;
            a_p = x;
            b_p = b[temp];
        }
    }
    cout << a_p << " " << b_p;
}

int main()
{
    vector<int> a1{-1, 5, 10, 20, 3};
    vector<int> a2{26, 134, 135, 15, 17};
    min_pair(a1, a2);
}