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

int binary_search_recursive(vector<int> &arr, int start, int end, int target)
{
    if (end == start)
    {
        if (arr[end] == target)
        {
            return end;
        }
        return -1;
    }
    int mid;
    mid = (start + end) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        return binary_search_recursive(arr, start, mid - 1, target);
    }
    else
    {
        return binary_search_recursive(arr, mid + 1, end, target);
    }
}

int binary_search(vector<int> &arr, int start, int end, int target)
{
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7};
    sort(arr.begin(), arr.end());
    cout << binary_search(arr, 0, arr.size() - 1, 5);
}
