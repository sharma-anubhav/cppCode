#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

void subsets_string(string s, int i, string curr_string)
{
    if (i == s.size())
    {
        cout << curr_string << endl;
        return;
    }
    subsets_string(s, i + 1, curr_string);
    subsets_string(s, i + 1, curr_string + s[i]);
    return;
}

int main()
{
    string a = "";
    int i = 0;
    string s = "abc";
    subsets_string(s, i, a);
}