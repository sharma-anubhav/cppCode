#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

void smart_keypad(string inp, vector<string> keypad, int i, string cur_string)
{
    if (i == inp.size())
    {
        cout << cur_string << endl;
        return;
    }
    int num_int = inp[i] - '0';
    for (auto x : keypad[num_int])
    {
        smart_keypad(inp, keypad, i + 1, cur_string + x);
    }
    return;
}

int main()
{
    vector<string> keypad{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    // generate_brackets(3,0,0,0,"");
    smart_keypad("23", keypad, 0, "");
}
