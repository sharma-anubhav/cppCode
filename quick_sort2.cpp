#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int pivot(int arr[], int start, int end)
{
    int ele = arr[end];

    int i = start - 1;

    for (int k = start; k < end; k++)
    {
        if (arr[k] < ele)
        {
            swap(arr[i + 1], arr[k]);
            i++;
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quick_sort(int arr[], int start, int end)
{
    // base case
    if (end - start + 1 <= 1)
    {
        return;
    }

    // recursive case
    int p = pivot(arr, start, end);
    quick_sort(arr, start, p - 1);
    quick_sort(arr, p + 1, end);
}

int main()
{
    int arr[]{5, 2, 6, 1, 3, 9, 11, 4};
    quick_sort(arr, 0, 7);
    for (auto x : arr)
    {
        cout << x << " ";
    }
}
