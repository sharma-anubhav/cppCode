#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <limits.h>
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <limits.h>
using namespace std;

// Better Code than below one
pair<int, int> subarray_sort(vector<int> arr)
{
    int smallest = INT_MAX;
    int largest = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (arr[i + 1] < arr[i])
            {
                smallest = min(arr[i], smallest);
                largest = max(arr[i], largest);
            }
        }
        else if (i == n - 1)
        {
            if (arr[i - 1] > arr[i])
            {
                smallest = min(arr[i], smallest);
                largest = max(arr[i], largest);
            }
        }
        else if (arr[i] > arr[i + 1] or arr[i] < arr[i - 1])
        {
            smallest = min(arr[i], smallest);
            largest = max(arr[i], largest);
        }
    }
    int left = 0;
    while (smallest >= arr[left])
    {
        left++;
    }
    int right = n - 1;
    while (largest <= arr[right])
    {
        right--;
    }
    return make_pair(left, right);
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    pair<int, int> indexes;
    indexes = subarray_sort(arr);
    cout << indexes.first << " " << indexes.second;
}

// BEKAR CODE
pair<int, int> subarray_sort(vector<int> arr)
{
    int smallest = INT_MAX;
    int largest = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (arr[i + 1] < arr[i])
            {
                smallest = min(arr[i], smallest);
                largest = max(arr[i], largest);
            }
        }
        else if (i == n - 1)
        {
            if (arr[i - 1] > arr[i])
            {
                smallest = min(arr[i], smallest);
                largest = max(arr[i], largest);
            }
        }
        else if (arr[i] > arr[i + 1] or arr[i] < arr[i - 1])
        {
            smallest = min(arr[i], smallest);
            largest = max(arr[i], largest);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > smallest)
        {
            smallest = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] < largest)
        {
            largest = i;
            break;
        }
    }
    return make_pair(smallest, largest);
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    pair<int, int> indexes;
    indexes = subarray_sort(arr);
    cout << indexes.first << " " << indexes.second;
}
