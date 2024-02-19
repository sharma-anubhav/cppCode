#include <bits/stdc++.h>
using namespace std;

int MaxValue(int n, vector<int> v)
{
    if (n == 1)
    {
        return *v.begin();
    }
    else if (n == 2)
    {
        return max(*v.begin(), *(v.end() - 1));
    }

    int pick_start_end = *v.begin() + MaxValue(n - 2, {v.begin() + 1, v.end() - 1});
    int pick_start_start = *v.begin() + MaxValue(n - 2, {v.begin() + 2, v.end()});
    int pick_end_start = *(v.end() - 1) + MaxValue(n - 2, {v.begin() + 1, v.end() - 1});
    int pick_end_end = *(v.end() - 1) + MaxValue(n - 2, {v.begin(), v.end() - 2});

    return max(min(pick_start_start, pick_start_end), min(pick_end_end, pick_end_start));
}
