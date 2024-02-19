#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

int ladders(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    if (n == 3)
    {
        return 4;
    }
    else
    {
        return ladders(n - 1) + ladders(n - 2) + ladders(n - 3);
    }
}

int main()
{
    cout << ladders(4);
}