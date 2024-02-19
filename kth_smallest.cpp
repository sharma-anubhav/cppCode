#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <limits.h>
#include <string>
using namespace std;

int pivot(vector<int> &arr, int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;
    int j = start;

    while (j < end)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i + 1], arr[j]);
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    swap(arr[end], arr[i + 1]);
    return i + 1;
}

int kth_smallest(vector<int> &arr, int start, int end, int k)
{
    int p;
    if (end - (start + 1) < 1)
    {
        return arr[start];
    }

    p = pivot(arr, start, end);
    if (p == (k - 1))
    {
        return arr[p];
    }
    else if (p > (k - 1))
    {
        return kth_smallest(arr, start, p - 1, k);
    }
    else
    {
        return kth_smallest(arr, p + 1, end, k);
    }
}

int main()
{
    vector<int> arr{10, 5, 1, 4, 7, 2};
    // quick_sort(arr, 0, arr.size()-1);
    cout << kth_smallest(arr, 0, arr.size() - 1, 2);
}
