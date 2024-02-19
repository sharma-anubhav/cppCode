#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mountain(vector<int> arr)
{
    int largest = 0;

    for (int i = 1; i < arr.size() - 1; i++)
    {
        if (arr[i + 1] < arr[i] && arr[i] > arr[i - 1])
        {
            int j = i - 1;
            int local_len = 1;
            while (j >= 0 && arr[j] < arr[j + 1])
            {
                local_len++;
                j--;
            }
            int k = i + 1;
            while (k <= arr.size() - 1 && arr[k + 1] < arr[k - 1])
            {
                local_len++;
                k++;
            }
            if (local_len > largest)
            {
                largest = local_len;
            }
        }
    }
    return largest;
}

int main()
{
    vector<int> arr{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    int len;

    len = mountain(arr);
    cout << len;
}
