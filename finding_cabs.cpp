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

class car
{
public:
    int x, y;
    string id;

    car(string id, int x, int y)
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }
};

int dis(car c)
{
    return (c.x) * (c.x) + (c.y) * (c.y);
}

class Compare
{
public:
    bool operator()(car a, car b)
    {
        return dis(a) < dis(b);
    }
};

void find_cabs(vector<car> v, int k)
{
    priority_queue<car, vector<car>, Compare> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(v[i]);
    }

    for (int i = k; i < v.size(); i++)
    {
        if (dis(pq.top()) > dis(v[i]))
        {
            pq.pop();
            pq.push(v[i]);
        }
    }

    while (!pq.empty())
    {
        cout << pq.top().id << " ";
        pq.pop();
    }
    return;
}

int main()
{
    int n, k;
    vector<car> v;

    cin >> n >> k;

    string id;
    int x, y;

    for (int i = 0; i < n; i++)
    {
        cin >> id >> x >> y;
        car c(id, x, y);
        v.push_back(c);
    }

    find_cabs(v, k);
}
