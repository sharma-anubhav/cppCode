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

void quick_sort(vector<int> &arr, int start, int end)
{
    int p;
    if (end - start + 1 < 1)
    {
        return;
    }

    p = pivot(arr, start, end);
    quick_sort(arr, start, p - 1);
    quick_sort(arr, p + 1, end);
}

int main()
{
    vector<int> arr{10, 5, 1, 4};
    quick_sort(arr, 0, arr.size() - 1);
    for (auto x : arr)
    {
        cout << x << " ";
    }
}
