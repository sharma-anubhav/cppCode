#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <limits.h>
#include <string>
using namespace std;

void longest_unique_substring(string s)
{
    unordered_set<char> tracker;
    int start = 0;
    int end = 0;
    int longest = 0;
    pair<int, int> idx;
    idx.first = 0;
    idx.second = 0;
    int local_len = 0;
    while (end < s.size())
    {
        if (tracker.find(s[end]) == tracker.end())
        {
            tracker.insert(s[end]);
            local_len++;
            end++;
            if (local_len >= longest)
            {
                longest = local_len;
                idx.first = start;
                idx.second = end;
            }
        }
        else
        {
            while (s[start] != s[end] and start < end)
            {
                local_len--;
                tracker.erase(s[start]);
                start++;
            }
            start++;
            // tracker.erase(s[start]);
            end++;
        }
    }

    cout << s.substr(idx.first, idx.second);
    return;
}

int main()
{
    string a = "abcabed";
    longest_unique_substring(a);
}
