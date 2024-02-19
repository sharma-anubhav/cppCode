#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int rains(vector<int> arr)
{
    int n = arr.size();
    int water = 0;
    vector<int> lmax(n, 0);
    vector<int> rmax(n, 0);

    lmax[0] = arr[0];
    rmax[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++)
    {
        lmax[i] = max(arr[i], lmax[i - 1]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        rmax[i] = max(arr[i], rmax[i + 1]);
    }

    for (int i = 0; i < n; i++)
    {
        water += min(lmax[i], rmax[i]) - arr[i];
    }
    return water;
}

int main()
{
    vector<int> arr{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int water;
    water = rains(arr);
    cout << water;
}
