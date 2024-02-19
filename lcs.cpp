/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int lcs(string s1, string s2, int i, int j)
{
    // base case
    if (i >= s1.size())
    {
        return 0;
    }
    if (j >= s2.size())
    {
        return 0;
    }
    // recursive case
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    if (s1[i] == s2[j])
    {
        count1 = 1 + lcs(s1, s2, i + 1, j + 1);
    }
    else
    {
        count2 = lcs(s1, s2, i, j + 1);
        count3 = lcs(s1, s2, i + 1, j);
    }

    return max(count3, max(count1, count2));
}

int main()
{
    string s1 = "ABCD";
    string s2 = "ABEDG";

    cout << lcs(s1, s2, 0, 0);

    return 0;
}

// A B C D
// A B E D G
