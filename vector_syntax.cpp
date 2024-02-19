#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // initiate
    // vector<int> b(1, 2, 3, 4);
    vector<int> a;

    // pushback
    a.push_back(1);
    for (auto x : a)
    {
        cout << x << endl;
    }

    // size and capacity
    cout << a.size() << endl;
    cout << a.capacity() << endl;

    a.push_back(2);
    a.push_back(2);
    a.push_back(2);
    a.push_back(2);
    a.push_back(2);

    cout << a.size() << endl;
    cout << a.capacity() << endl;

    // Iterator traverse
    for (auto it = a.begin(); it != a.end(); it++)
        cout << *it << " ";
    cout << endl;

    // REFERENCE PASS by and access;
    cout << "front: " << a.front() << endl;
    // int &c = a[0];
    // int c = a[0];
    // int c = a.front();
    int &c = a.front();
    cout << c << endl;
    a[0] = 2;
    cout << "a.front() new: " << a[0] << " c now: " << c << endl;
    // INSERT
    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << endl;
    a.insert(a.begin() + 3, 0);
    for (auto x : a)
    {
        cout << x << " ";
    }
}
