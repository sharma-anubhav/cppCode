#include <vector>
#include <set>
using namespace std;

class node
{
public:
    int x;
    int y;
    int w;

    node(int X, int Y, int W)
    {
        x = X;
        y = Y;
        w = W;
    }
};

class cmp
{
public:
    bool operator()(node a, node b) const
    {
        return a.w <= b.w;
    }
};

int shortest_path(vector<vector<int>> grid)
{
    // return the shortest path len
    int r = grid.size();
    int c = grid[0].size();

    vector<vector<int>> distance(r + 1, vector<int>(c + 1, INT_MAX));

    distance[0][0] = grid[0][0];

    vector<int> dx{0, 0, -1, 1};
    vector<int> dy{1, -1, 0, 0};

    set<node, cmp> s;
    s.insert(node(0, 0, distance[0][0]));

    while (!s.empty())
    {
        int cur_x = (*s.begin()).x;
        int cur_y = (*s.begin()).y;
        int cur_weight = (*s.begin()).w;

        s.erase(s.begin());

        for (int i = 0; i < 4; i++)
        {
            int n_x = cur_x + dx[i];
            int n_y = cur_y + dy[i];

            if (n_x >= 0 and n_x < c and n_y >= 0 and n_y < r)
            {
                if (cur_weight + grid[n_x][n_y] < distance[n_x][n_y])
                {
                    auto f = s.find(node(n_x, n_y, distance[n_x][n_y]));
                    if (f != s.end())
                    {
                        s.erase(f);
                    }
                    distance[n_x][n_y] = cur_weight + grid[n_x][n_y];
                    s.insert(node(n_x, n_y, distance[n_x][n_y]));
                }
            }
        }
    }
    return distance[r - 1][c - 1];
}
