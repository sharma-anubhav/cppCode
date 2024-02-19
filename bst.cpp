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

void insert_iterative(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return;
    }

    node *temp = root;
    node *prev;

    while (temp != NULL)
    {
        prev = temp;
        if (data <= temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    if (data <= prev->data)
    {
        prev->left = new node(data);
    }
    else
    {
        prev->right = new node(data);
    }

    return;
}

node *insert_recursive(node *root, int data)
{
    if (root == NULL)
    {
        return new node(data);
    }

    if (data <= root->data)
    {
        root->left = insert_recursive(root->left, data);
    }
    else
    {
        root->right = insert_recursive(root->right, data);
    }
    return root;
}

void in_order(node *root)
{
    if (root == NULL)
    {
        return;
    }

    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
    return;
}

node *make_bst_sorted_array(vector<int> v, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;
    int data = v[mid];
    node *root = new node(data);

    root->left = make_bst_sorted_array(v, s, mid - 1);
    root->right = make_bst_sorted_array(v, mid + 1, e);

    return root;
}

int find_closest(node *root, int target)
{
    if (root == NULL)
    {
        return INT_MAX;
    }

    int closest;
    if (target == root->data)
    {
        return target;
    }
    else
    {
        if (target > root->data)
        {
            closest = find_closest(root->right, target);
        }
        else
        {
            closest = find_closest(root->left, target);
        }
        if (abs(closest - target) < abs(target - root->data))
        {
            return closest;
        }
        else
        {
            return root->data;
        }
    }
}

int getMax(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->key;
}

int getMin(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->key;
}

bool isBST(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL and root->right == NULL)
    {
        return true;
    }

    if (isBST(root->left) and isBST(root->right))
    {
        if (root->left)
        {
            if (root->key < getMax(root->left))
            {
                return false;
            }
        }
        if (root->right)
        {
            if (root->key > getMin(root->right))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main()
{
    // node* root = NULL;
    // vector<int> v{8,3,10,1,6,14,4,7,13};
    // for(auto x:v){
    //     root = insert_recursive(root, x);
    // }
    node *root = build_tree_level();
    cout << isbst(root);
}