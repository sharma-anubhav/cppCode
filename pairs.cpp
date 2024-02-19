#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
using namespace std;

vector<pair<int, int>> find_pairs(vector<int> a, int target)
{
    vector<pair<int, int>> ans;
    unordered_set<int> track;
    for (auto x : a)
    {
        int need = target - x;
        if (track.find(need) != track.end())
        {
            ans.push_back(make_pair(x, need));
        }
        track.insert(x);
    }
    return ans;
}

int main()
{
    vector<int> a;
    a.push_back(10);
    a.push_back(3);
    a.push_back(1);
    a.push_back(5);
    a.push_back(-1);
    a.push_back(-6);
    a.push_back(3);
    a.push_back(4);
    a.push_back(0);
    a.push_back(11);

    for (auto x : a)
        cout << x << " ";

    vector<pair<int, int>> ans;
    ans = find_pairs(a, 4);

    for (auto pair : ans)
    {
        cout << pair.first << " " << pair.second << endl;
    }
}