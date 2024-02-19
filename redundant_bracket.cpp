#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <limits.h>
#include <string>
#include <stack>

using namespace std;

bool redundant_paranthesis(string s)
{
    stack<char> a;
    for (char x : s)
    {
        switch (x)
        {
        case '+':
        case '-':
        case '/':
        case '*':
        case '(':
            a.push(x);
            break;

        case ')':
            if (!a.empty() and a.top() == '(')
            {
                return true;
            }
            else
            {
                while (a.top() == '*' or a.top() == '/' or a.top() == '+' or a.top() == '-')
                {
                    a.pop();
                }
                if (!a.empty() and a.top() == '(')
                    a.pop();
                else
                    return true;
            }
            break;
        default:
            continue;
        }
    }
    return false;
}
// 8-7-6-5-4-3-2-1-NULL

int main()
{
    string s = "((a+b))+c) + (d*e)";
    cout << redundant_paranthesis(s);
}
