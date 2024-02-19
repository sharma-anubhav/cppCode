#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int start, int mid, int end)
{

    int arr_temp[end - start + 1];

    int l_s = start;
    int l_e = mid;
    int r_s = mid + 1;
    int r_e = end;

    int i = 0;
    while (l_s <= l_e and r_s <= r_e)
    {
        if (arr[l_s] <= arr[r_s])
        {
            arr_temp[i] = arr[l_s];
            l_s += 1;
            i += 1;
        }
        else
        {
            arr_temp[i] = arr[r_s];
            r_s += 1;
            i += 1;
        }
    }

    while (l_s <= l_e)
    {
        arr_temp[i] = arr[l_s];
        l_s += 1;
        i += 1;
    }
    while (r_s <= r_e)
    {
        arr_temp[i] = arr[r_s];
        r_s += 1;
        i += 1;
    }

    int j = 0;
    for (int i = start; i <= end; i++)
    {
        arr[i] = arr_temp[j];
        j++;
    }
}

void merge_sort(int arr[], int start, int end)
{
    // base case
    if (start == end)
    {
        return;
    }

    // recursive case
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main()
{
    int arr[]{5, 2, 6, 1, 3, 9, 11, 4};
    merge_sort(arr, 0, 7);
    for (auto x : arr)
    {
        cout << x << " ";
    }
}
