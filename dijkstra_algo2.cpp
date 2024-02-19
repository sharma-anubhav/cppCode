// Online C++ compiler to run C++ program online
#include <iostream>
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

        int dis[v] = {0};
        for (int i = 1; i < v; i++)
        {
            dis[i] = INT_MAX;
        }

        set<pair<int, int>, cmp> set;
        set.insert({s, dis[s]});

        while (!set.empty())
        {
            auto [node, ndis] = *set.begin();
            set.erase(set.begin());

            for (auto [nbr, w] : l[node])
            {

                int new_dis = ndis + w;

                if (new_dis < dis[nbr])
                {

                    auto f = set.find({nbr, dis[nbr]});

                    if (f != set.end())
                        set.erase(f);

                    dis[nbr] = new_dis;
                    set.insert({nbr, new_dis});
                }
            }
        }
        for (int i = 0; i < v; i++)
        {
            cout << "distance of " << i << " from " << s << " is: " << dis[i] << endl;
        }
    }
};
main()
{
    w_graph g = w_graph(5);
    g.insert_w_edge(0, 1, 4);
    g.insert_w_edge(1, 2, 1);
    g.insert_w_edge(0, 2, 4);
    g.insert_w_edge(0, 3, 7);
    g.insert_w_edge(3, 2, 2);
    g.insert_w_edge(3, 4, 3);
    // g.print_graph();
    g.dijkstra(0);

    return 0;
}