#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

bool is_safe(bool state[20][20], int i, int j, int n)
{
    int temp_j_1 = j;
    int temp_j_2 = j;
    int temp_i_1 = i;
    int temp_i_2 = i;

    while (i >= 0)
    {
        if (state[i][j] == true)
        {
            return false;
        }
        i--;
    }
    while (temp_i_1 >= 0 and temp_j_1 >= 0)
    {
        if (state[temp_i_1][temp_j_1] == true)
        {
            return false;
        }
        temp_i_1--;
        temp_j_1--;
    }
    while (temp_i_2 >= 0 and temp_j_2 < n)
    {
        if (state[temp_i_2][temp_j_2] == true)
        {
            return false;
        }
        temp_i_2--;
        temp_j_2++;
    }
    return true;
}

void print_state(bool state[20][20], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << state[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

bool n_queen_single(int n, int i, bool state[20][20])
{
    if (i == n)
    {
        print_state(state, n);
        return true;
    }
    for (int j = 0; j < n; j++)
    {
        if (is_safe(state, i, j, n))
        {
            state[i][j] = true;
            if (n_queen(n, i + 1, state))
            {
                return true;
            }
            else
            {
                state[i][j] = false;
            }
        }
    }

    return false;
}

void n_queen_all_count(int n, int i, bool state[20][20])
{
    if (i == n)
    {
        print_state(state, n);
        cout << endl
             << "================" << endl;
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (is_safe(state, i, j, n))
        {
            state[i][j] = true;
            n_queen(n, i + 1, state);
            state[i][j] = false;
        }
    }
}

int main()
{
    bool state[20][20];
    n_queen_single(4, 0, state);
}
