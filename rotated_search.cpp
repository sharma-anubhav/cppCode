#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <limits.h>
#include <string>
using namespace std;

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

int freq_count(vector<int> arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid;
    int count = 0;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == target)
        {
            count++;
            int l = mid - 1;
            int r = mid + 1;
            while (l >= 0 and arr[l] == target)
            {
                count++;
                l--;
            }
            while (r <= (arr.size() - 1) and arr[r] == target)
            {
                count++;
                r++;
            }
            return count;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return count;
}

int pivot_search(vector<int> arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }

        else if (arr[end] < arr[mid])
        {
            if (target >= arr[start] && target < arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else if (arr[end] > arr[mid])
        {
            if (target <= arr[end] && target > arr[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr{4, 5, 6, 7, 0, 1, 2, 3};
    // sort(arr.begin(), arr.end());
    cout << pivot_search(arr, 1);
}
