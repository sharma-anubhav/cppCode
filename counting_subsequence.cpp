/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int subsequence_count(string s1, string s2, int i, string cur)
{
    int n = s1.size();

    if (i == n)
    {
        return 0;
    }
    int count = 0;

    if (cur == s2)
    {
        return 1;
    }

    count += subsequence_count(s1, s2, i + 1, cur);
    count += subsequence_count(s1, s2, i + 1, cur + s1[i]);

    return count;
}

int main()
{
    string s1 = "ABCDCE";
    string s2 = "ABC";
    cout << subsequence_count(s1, s2, 0, "");
    return 0;
}