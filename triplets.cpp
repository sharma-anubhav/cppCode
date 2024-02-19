#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> triplets(vector<int> arr, int target)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = 0; i < n - 3; i++)
    {
        int j = i + 1;
        int k = n - 1;
        int need = target - arr[i];
        while (j < k)
        {
            int curr = arr[j] + arr[k];
            if (curr == need)
            {
                vector<int> temp{arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
            }
            else if (curr < need)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int sum = 18;

    vector<vector<int>> res;
    res = triplets(arr, sum);
    for (auto x : res)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}
