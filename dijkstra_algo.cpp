#include <bits/stdc++.h>
using namespace std;

class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b) const
    {
        return a.second < b.second;
    }
};

class w_graph
{
    int v;
    list<pair<int, int>> *l;

public:
    w_graph(int V)
    {
        v = V;
        l = new list<pair<int, int>>[v];
    }

    void insert_w_edge(int s, int e, int w, bool directed = false)
    {
        l[s].push_back({e, w});
        if (!directed)
        {
            l[e].push_back({s, w});
        }
        return;
    }

    void print_graph()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << " -> ";
            for (auto p : l[i])
            {
                cout << "{" << p.first << "," << p.second << "}, ";
            }
            cout << endl;
        }
    }

    void dijkstra(int s)
    {
        int *distance = new int[v];
        for (int i = 0; i < v; i++)
        {
            distance[i] = INT_MAX;
        }
        set<pair<int, int>, cmp> set;

        distance[s] = 0;
        set.insert({s, distance[s]});

        while (!set.empty())
        {
            int curr = (*set.begin()).first;
            int curr_dis = (*set.begin()).second;
            set.erase(set.begin());

            for (auto x : l[curr])
            {
                int next = x.first;
                int w = x.second;
                if (distance[next] > (curr_dis + w))
                {
                    auto f = set.find({next, distance[next]});
                    if (f != set.end())
                    {
                        set.erase(f);
                    }
                    distance[next] = curr_dis + w;
                    set.insert({next, distance[next]});
                }
            }
        }

        for (int i = 0; i < v; i++)
        {
            cout << "distance of " << i << " from " << s << " is: " << distance[i] << endl;
        }
    }
};

int main()
{
    w_graph g = w_graph(5);
    g.insert_w_edge(0, 1, 1);
    g.insert_w_edge(1, 2, 1);
    g.insert_w_edge(0, 2, 4);
    g.insert_w_edge(0, 3, 7);
    g.insert_w_edge(3, 2, 2);
    g.insert_w_edge(3, 4, 3);
    // g.print_graph();
    g.dijkstra(0);
}
