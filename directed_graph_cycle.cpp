#include <bits/stdc++.h>
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

    bool contains_cycle_directed_helper(int s, bool *visited, bool *cur_state)
    {
        visited[s] = true;
        cur_state[s] = true;

        for (auto nbr : l[s])
        {

            if (cur_state[nbr] == true)
                return true;
            if (!visited[nbr])
            {
                if (contains_cycle_directed_helper(nbr, visited, cur_state))
                    return true;
            }
        }

        cur_state[s] = false;
        return false;
    }

    bool contains_cycle_directed(int v)
    {
        bool *visited = new bool[v]{0};
        bool *cur_state = new bool[v]{0};

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                if (contains_cycle_directed_helper(i, visited, cur_state))
                    return true;
            }
        }
        return false;
    }
};

bool contains_cycle(int v, vector<pair<int, int>> edges)
{
    // Complete this method
    graph g = graph(v);
    for (auto pair : edges)
    {
        g.insert_edge(pair.first, pair.second, true);
    }

    return g.contains_cycle_directed(v);
}