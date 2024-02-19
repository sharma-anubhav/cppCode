#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <limits.h>
using namespace std;

void housing2(vector<int> arr, int target)
{
    int i = 0;
    int j = 0;
    int cs = 0;

    while (j < arr.size())
    {
        cs += arr[j];
        j++;

        while (cs > target and i < j)
        {
            cs -= arr[i];
            i++;
        }
        if (cs == target)
        {
            cout << i << " " << j - 1 << endl;
        }
    }
    return;
}

void housing(vector<int> arr, int target)
{
    int win_sum = arr[0];
    int start = 0;
    int end = 0;

    while (end < arr.size())
    {
        if (win_sum == target)
        {
            cout << start << " " << end << endl;
            end++;
            win_sum += arr[end];
        }
        if (win_sum < target)
        {
            end++;
            win_sum += arr[end];
        }
        else if (win_sum > target)
        {
            win_sum -= arr[start];
            start++;
        }
    }
}

int main()
{
    vector<int> a{1, 3, 2, 1, 4, 1, 3, 2, 1, 1};
    housing2(a, 8);
}

///////****** QUESTION ***********
// why do we pass node
