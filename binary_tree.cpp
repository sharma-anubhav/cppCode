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

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *build_tree_depth()
{
    int n;
    cin >> n;

    if (n == -1)
    {
        return NULL;
    }

    node *root = new node(n);
    root->left = build_tree_depth();
    root->right = build_tree_depth();

    return root;
}

void level_order_print(node *root)
{
    queue<node *> tracker;

    if (root == NULL)
    {
        cout << "Empty tree";
        return;
    }

    tracker.push(root);
    tracker.push(NULL);
    while (!tracker.empty())
    {
        node *temp = tracker.front();
        if (temp == NULL)
        {
            cout << endl;
            tracker.pop();
            if (!tracker.empty())
            {
                tracker.push(NULL);
            }
        }
        else
        {
            cout << tracker.front()->data << " ";
            if (temp->left)
                tracker.push(temp->left);
            if (temp->right)
                tracker.push(temp->right);
            tracker.pop();
        }
    }
    return;
}

node *build_tree_level()
{
    int d;
    cin >> d;
    node *root = new node(d);

    queue<node *> tracker;
    tracker.push(root);

    while (!tracker.empty())
    {
        node *temp = tracker.front();
        int l, r;

        cin >> l;
        cin >> r;

        if (l != -1)
        {
            temp->left = new node(l);
            tracker.push(temp->left);
        }
        if (r != -1)
        {
            temp->right = new node(r);
            tracker.push(temp->right);
        }
        tracker.pop();
    }

    return root;
}

int get_height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int l_height = 1 + get_height(root->left);
    int r_height = 1 + get_height(root->right);

    return max(l_height, r_height);
}

int get_diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int l_dia = get_diameter(root->left);
    int r_dia = get_diameter(root->right);
    int h = get_height(root->left) + get_height(root->right);

    return max(h, max(l_dia, r_dia));
}

pair<int, int> get_diameter_optimized(node *root)
{
    if (root == NULL)
    {
        return {0, 0};
    }
    pair<int, int> l_dh = get_diameter_optimized(root->left);
    pair<int, int> r_dh = get_diameter_optimized(root->right);

    int h = 1 + max(l_dh.second, r_dh.second);
    int d = max(l_dh.second + r_dh.second, max(l_dh.first, r_dh.first));
    return {d, h};
}

int replace_descendant_sum(node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL and root->right == NULL)
    {
        return root->data;
    }

    // post order traversal

    int l_sum_desc = replace_descendant_sum(root->left);
    int r_sum_desc = replace_descendant_sum(root->right);
    int node_data = root->data;

    root->data = l_sum_desc + r_sum_desc;
    return l_sum_desc + r_sum_desc + node_data;
}

pair<bool, int> height_balance_tree(node *root)
{
    if (root == NULL)
    {
        return {true, 0};
    }
    pair<bool, int> l_pair = height_balance_tree(root->left);
    pair<bool, int> r_pair = height_balance_tree(root->right);

    if (l_pair.first and r_pair.first)
    {
        if (abs(l_pair.second - r_pair.second) <= 1)
        {
            return {true, max(l_pair.second, r_pair.second) + 1};
        }
        else
        {
            return {false, max(l_pair.second, r_pair.second) + 1};
        }
    }
    else
    {
        return {false, max(l_pair.second, r_pair.second) + 1};
    }
}

pair<bool, int> height_balance_tree_better(node *root)
{
    if (root == NULL)
    {
        return {true, 0};
    }
    pair<bool, int> l_pair = height_balance_tree(root->left);
    pair<bool, int> r_pair = height_balance_tree(root->right);

    if (l_pair.first and r_pair.first and abs(l_pair.second - r_pair.second) <= 1)
    {
        return {true, max(l_pair.second, r_pair.second) + 1};
    }
    else
    {
        return {false, max(l_pair.second, r_pair.second) + 1};
    }
}

pair<int, int> max_subset_sum(node *root)
{
    if (root == NULL)
    {
        return {0, 0};
    }

    pair<int, int> l_pair = max_subset_sum(root->left);
    pair<int, int> r_pair = max_subset_sum(root->right);
    // include
    int include = root->data + l_pair.second + r_pair.second;
    // exclude

    int exclude = max(l_pair.first, l_pair.second) + max(r_pair.first, r_pair.second);
    return {include, exclude};
}

void print_at_levelk(node *root, int k, int cur_height)
{
    if (root == NULL)
    {
        return;
    }
    if (cur_height == k)
    {
        cout << root->data << " ";
        return;
    }

    print_at_levelk(root->left, k, cur_height + 1);
    print_at_levelk(root->right, k, cur_height + 1);
    return;
}

void print_at_levelk_better(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    print_at_levelk_better(root->left, k - 1);
    print_at_levelk_better(root->right, k - 1);
    return;
}

// 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1  -->depth build_tree
// 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1  -->build_tree_level
int main()
{
    node *root = build_tree_level();
    level_order_print(root);
    cout << endl;
    print_at_levelk_better(root, 2);
    return 0;
}