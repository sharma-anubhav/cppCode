#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>

using namespace std;

int main()
{
    cout << "$$$$$$$$$ unordered MAP $$$$$$$$$$$" << endl;

    unordered_map<int, int> a;
    a[2] = 2;
    a[3] = 3;
    a[1] = 4;

    // traverse
    for (auto x : a)
    {
        cout << x.first << " " << x.second << endl;
    }

    // MAP
    cout << "$$$$$$$$$ MAP $$$$$$$$$$$" << endl;
    map<int, int> b;
    b[2] = 2;
    b[3] = 3;
    b[1] = 4;

    // traverse interator
    for (auto it = b.begin(); it != b.end(); it++)
        cout << it->first << " " << it->second << endl;
    cout << endl;

    // finding a key
    if (a.find(1) == a.end())
        cout << "not found" << endl;
    else
        cout << "Found" << endl;
}