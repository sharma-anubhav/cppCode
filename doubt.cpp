#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    cout << a.capacity();
    cout << a.size();
    cout << a[100];
    cout << a.capacity();
}