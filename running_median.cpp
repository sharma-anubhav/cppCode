/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <limits.h>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{

    int d;
    cin >> d;

    priority_queue<int> pql;
    priority_queue<int, vector<int>, greater<int>> pqr;

    double median;

    median = d;
    pql.push(d);
    cout << "Current median is: " << median << endl;

    cin >> d;

    while (d != -1)
    {
        if (pql.size() > pqr.size() and d <= median)
        {
            int temp = pql.top();
            pql.pop();
            pqr.push(temp);
            pql.push(d);
            median = (pql.top() + pqr.top()) / 2.0;
        }
        else if (pqr.size() > pql.size() and d > median)
        {
            int temp = pqr.top();
            pqr.pop();
            pql.push(temp);
            pqr.push(d);
            median = (pql.top() + pqr.top()) / 2.0;
        }
        else
        {
            if (d <= median)
            {
                pql.push(d);
                median = pql.top();
            }
            else
            {
                pqr.push(d);
                median = pqr.top();
            }
        }

        cout << "Current median is: " << median << endl;

        cin >> d;
    }

    return 0;
}
