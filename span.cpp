#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

class live_data
{
    vector<int> a;
    // <int, int> = <span, index of largest before>
    vector<pair<int, int>> span_state;

public:
    live_data() {}

    void insert(int n)
    {
        // 0 elements
        if (a.size() == 0)
        {
            a.push_back(n);
            span_state.push_back({0, -1});
            return;
        }
        // if new element less than previous element
        if (n < a[a.size() - 1])
        {
            span_state.push_back({0, a.size() - 1});
            a.push_back(n);
        }
        // new element greater than previous
        else
        {
            int i = a.size() - 1;
            int curr_span = span_state[i].first + 1;
            a.push_back(n);
            // traverse back to the largest element than n
            // -1 index means that there is no larger element before
            while (a[span_state[i].second] < n and span_state[i].second >= 0)
            {
                i = span_state[i].second;
                curr_span = curr_span + 1 + span_state[i].first;
            }
            if (span_state[i].second < 0)
            {
                span_state.push_back({curr_span, -1});
            }
            else
            {
                span_state.push_back({curr_span, span_state[i].second});
            }
            return;
        }
    }
    void get_span()
    {
        for (auto x : span_state)
        {
            cout << x.first << " " << x.second << endl;
        }
        return;
    }
};
// 92, 91, 96, 105, 99, 90, 91, 92, 100
// 92, 93, 94 , 91

int main()
{
    live_data data;
    data.insert(92);
    data.insert(91);
    data.insert(96);
    data.insert(105);
    data.insert(99);
    data.insert(90);
    data.insert(91);
    data.insert(92);
    data.insert(100);
    data.get_span();
}
