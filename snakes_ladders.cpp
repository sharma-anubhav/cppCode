/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <list>
#include <queue>
using namespace std;

class graph
{
    int v;
    list<int> *l;

public:
    graph(int V)
    {
        v = V;
        l = new list<int>[v];
    }

    void insert_edge(int s, int e, bool directed = false)
    {
        l[s].push_back(e);
        if (!directed)
        {
            l[e].push_back(s);
        }
        return;
    }

    void print_graph()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << " --> ";
            for (auto x : l[i])
            {
                cout << x << " - ";
            }
            cout << endl;
        }
        return;
    }

    void bfs(int s)
    {
        queue<int> q;
        bool *visited = new bool[v]{0};

        visited[s] = true;
        q.push(s);

        while (!q.empty())
        {
            int front = q.front();
            cout << front << " ";
            q.pop();

            for (auto x : l[front])
            {
                if (!visited[x])
                {
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
    }

    int shortest_dis_s_e(int s, int e)
    {
        queue<int> q;

        bool *visited = new bool[v]{0};
        int *dis = new int[v];

        dis[s] = 0;
        visited[s] = true;
        q.push(s);

        while (!q.empty())
        {
            int front = q.front();

            for (auto x : l[front])
            {
                if (!visited[x])
                {
                    q.push(x);
                    dis[x] = dis[front] + 1;
                    visited[x] = true;
                }
            }
            q.pop();
        }
        return dis[e];
    }
};

int min_dice_throws(int n, vector<pair<int, int>> snakes, vector<pair<int, int>> ladders)
{
    int *board = new int[n + 1]{0};

    for (auto x : snakes)
    {
        board[x.first] = x.second - x.first;
    }
    for (auto x : ladders)
    {
        board[x.first] = x.second - x.first;
    }

    graph g = graph(n + 1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            int s = i;
            int e = s + j + board[s + j];
            if (s + j <= n)
            {
                g.insert_edge(s, e, true);
            }
        }
    }

    return g.shortest_dis_s_e(1, n);
}

int main()
{
    graph g = graph(7);

    g.insert_edge(0, 1);
    g.insert_edge(1, 2);
    g.insert_edge(2, 3);
    g.insert_edge(3, 5);
    g.insert_edge(5, 6);
    g.insert_edge(4, 5);
    g.insert_edge(0, 4);
    g.insert_edge(3, 4);
    cout << g.shortest_dis_s_e(1, 6);
    return 0;
}