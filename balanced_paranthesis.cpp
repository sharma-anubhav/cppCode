#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <limits.h>
#include <string>
#include <stack>

using namespace std;

bool balanced_paranthesis(string s)
{
    stack<char> a;
    for (char x : s)
    {
        switch (x)
        {
        case '(':
        case '{':
        case '[':
            a.push(x);
            break;

        case ')':
            if (!a.empty() and a.top() == '(')
            {
                a.pop();
            }
            else
            {
                return false;
            }
            break;
        case ']':
            if (!a.empty() and a.top() == '[')
            {
                a.pop();
            }
            else
            {
                return false;
            }
            break;
        case '}':
            if (!a.empty() and a.top() == '{')
            {
                a.pop();
            }
            else
            {
                return false;
            }
            break;
        default:
            continue;
        }
    }
    return a.empty();
}
// 8-7-6-5-4-3-2-1-NULL

int main()
{
    string s = "{a+(b+c)+([d+e]*f))}+k";
    cout << balanced_paranthesis(s);
}
