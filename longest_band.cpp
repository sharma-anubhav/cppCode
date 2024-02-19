#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int longest_band(vector<int> arr)
{
    unordered_set<int> tracker;
    for (auto x : arr)
    {
        tracker.insert(x);
    }

    int length = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int local_len = 1;
        int next = arr[i] + 1;
        while (tracker.find(next) != tracker.end())
        {
            local_len++;
            next++;
        }
        length = max(local_len, length);
    }
    return length;
}

int main()
{
    vector<int> arr{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
    int len;

    len = longest_band(arr);
    cout << len;
}
