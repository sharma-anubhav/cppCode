#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

void generate_brackets(int n, int i, int open, int close, string cur_string)
{
    if (close > open)
    {
        return;
    }
    if (i == (2 * n))
    {
        if (open == close)
        {
            cout << cur_string << endl;
            return;
        }
        return;
    }
    generate_brackets(n, i + 1, open + 1, close, cur_string + "(");
    generate_brackets(n, i + 1, open, close + 1, cur_string + ")");

    return;
}

int main()
{
    generate_brackets(3, 0, 0, 0, "");
}
