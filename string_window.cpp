#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <limits.h>
#include <string>
using namespace std;

// This CODE IS NOTTTT Good. Question is good but i have missed a lot of corner cases.

bool present(unordered_map<char, int> m_a, string b)
{
    for (auto x : b)
    {
        if (m_a.find(x) == m_a.end())
        {
            return false;
        }
        else
        {
            if (m_a[x] == 0)
            {
                return false;
            }
            m_a[x]--;
        }
    }
    return true;
}

void string_window(string a, string b)
{
    unordered_map<char, int> m_a;
    int n = a.size();
    int start = 0;
    int end = 0;
    int smallest = INT_MAX;
    int local_cnt = 0;
    pair<int, int> idx{0, 0};

    while (end < n)
    {
        while (!present(m_a, b) and end < n)
        {
            m_a[a[end]]++;
            end++;
            local_cnt++;
        }
        if (end > n)
        {
            break;
        }
        if (local_cnt < smallest)
        {
            idx.first = start;
            idx.second = end - 1;
            smallest = min(local_cnt, smallest);
        }

        m_a[a[start]]--;
        start++;
        local_cnt--;
    }
    cout << "smallest set to: " << smallest << " " << idx.first << " " << idx.second << endl;
    cout << a.substr(idx.first, smallest);
}

int main()
{
    string a = "hello";
    string b = "eo";
    string_window(a, b);
}
