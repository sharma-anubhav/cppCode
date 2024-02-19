#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <limits.h>
#include <string>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end)
{
    int l_s = start;
    int l_e = mid;
    int r_s = mid + 1;
    int r_e = end;
    vector<int> temp;

    while (l_s <= l_e && r_s <= r_e)
    {
        if (arr[l_s] <= arr[r_s])
        {
            temp.push_back(arr[l_s]);
            l_s++;
        }
        else
        {
            temp.push_back(arr[r_s]);
            r_s++;
        }
    }

    while (l_s <= l_e)
    {
        temp.push_back(arr[l_s]);
        l_s++;
    }
    while (r_s <= r_e)
    {
        temp.push_back(arr[r_s]);
        r_s++;
    }

    int i = start;
    for (auto x : temp)
    {
        arr[i] = x;
        i++;
    }
}

void merge_sort(vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = (end + start) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main()
{
    vector<int> arr{10, 5, 1, 4};
    merge_sort(arr, 0, arr.size() - 1);
    for (auto x : arr)
    {
        cout << x << " ";
    }
}
