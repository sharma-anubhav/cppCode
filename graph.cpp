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
        int *parent = new int[v];

        parent[s] = s;
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
                    parent[x] = front;
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

    void dfs_helper(int source, bool *visited)
    {
        visited[source] = true;
        cout << source << " ";
        for (auto x : l[source])
        {
            if (!visited[x])
            {
                visited[x] = true;
                dfs_helper(x, visited);
            }
        }
    }

    void dfs(int start)
    {
        bool *visited = new bool[v];
        dfs_helper(start, visited);
    }

    bool bfs_cycle_undirected(int s)
    {
        queue<int> q;
        bool *visited = new bool[v]{0};
        int *parent = new int[v];

        parent[s] = s;
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
                    parent[x] = front;
                }
                else
                {
                    if (parent[front] != x)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

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
    g.dfs(1);
    return 0;
}