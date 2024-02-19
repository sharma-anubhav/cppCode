#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <limits.h>
#include <string>
#include <stack>
#include <queue>

using namespace std;

void first_non_repeating(string s)
{
    unordered_map<char, int> fmap;
    queue<char> non_repeating_queue;

    for (char x : s)
    {
        fmap[x]++;

        if (fmap[x] == 1)
        {
            non_repeating_queue.push(x);
        }

        if (!non_repeating_queue.empty() and x == non_repeating_queue.front())
        {
            while (fmap[non_repeating_queue.front()] != 1 and !non_repeating_queue.empty())
            {
                non_repeating_queue.pop();
            }
        }

        if (non_repeating_queue.empty())
        {
            cout << -1;
        }
        else
        {
            cout << non_repeating_queue.front();
        }
    }
}
// abcbda
//  8-7-6-5-4-3-2-1-NULL

int main()
{
    string s = "aabccbcd";
    first_non_repeating(s);
}
