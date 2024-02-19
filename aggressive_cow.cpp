#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

bool place(int dis, vector<int> nest, int birds)
{
    int prev = 0;
    int count = 1;
    for (int next = 1; next < nest.size(); next++)
    {
        if (nest[next] - nest[prev] >= dis)
        {
            prev = next;
            count++;
            if (count == birds)
            {
                return true;
            }
        }
    }
    return false;
}

int aggressive_cow(vector<int> nest, int birds)
{
    int min = 0;
    int max = nest[nest.size() - 1] - nest[0];
    int mid, ans;
    while (min <= max)
    {
        mid = (min + max) / 2;
        if (place(mid, nest, birds))
        {
            min = mid + 1;
            ans = mid;
        }
        else
        {
            max = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nest{1, 2, 4, 8, 9};
    int birds = 3;
    cout << aggressive_cow(nest, 3);
}