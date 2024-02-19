// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int val;
    node *left;
    node *right;

    node(int d)
    {
        val = d;
        left = NULL;
        right = NULL;
    }
};

node *depth_build()
{
    int n;
    cin >> n;

    if (n == -1)
    {
        return NULL;
    }

    node *head = new node(n);

    head->left = depth_build();
    head->right = depth_build();

    return head;
}

void depth_traverse_inorder(node *head)
{
    if (head == NULL)
    {
        return;
    }

    depth_traverse_inorder(head->left);
    cout << head->val << " ";
    depth_traverse_inorder(head->right);

    return;
}

void depth_traverse_preorder(node *head)
{
    if (head == NULL)
    {
        return;
    }

    cout << head->val << " ";
    depth_traverse_preorder(head->left);
    depth_traverse_preorder(head->right);

    return;
}

void depth_traverse_postorder(node *head)
{
    if (head == NULL)
    {
        return;
    }

    depth_traverse_postorder(head->left);
    depth_traverse_postorder(head->right);
    cout << head->val << " ";
    return;
}

node *level_build()
{
    int n;
    cin >> n;

    queue<node *> q;

    if (n == -1)
        return NULL;

    node *head = new node(n);
    q.push(head);

    while (!q.empty())
    {
        node *temp = q.front();

        int l;
        int r;
        cin >> l;
        cin >> r;

        if (l != -1)
        {
            temp->left = new node(l);
            q.push(temp->left);
        }
        if (r != -1)
        {
            temp->right = new node(r);
            q.push(temp->right);
        }
        q.pop();
    }
    return head;
}

void level_order_print(node *head)
{
    if (head == NULL)
        return;

    queue<node *> q;
    q.push(head);
    q.push(NULL);

    while (!q.empty())
    {
        if (q.front() == NULL)
        {
            q.pop();
            if (!q.empty())
                q.push(NULL);
            cout << endl;
        }
        else
        {
            cout << q.front()->val << " ";
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
    }

    return;
}

int get_height(node *head)
{
    if (head == NULL)
        return 0;

    return 1 + max(get_height(head->left), get_height(head->right));
}

int get_diameter(node *head)
{
    if (head == NULL)
        return 0;

    int left_dia = get_diameter(head->left);
    int right_dia = get_diameter(head->right);
    int h = get_height(head->left) + get_height(head->right);

    return max(h, max(left_dia, right_dia));
}

pair<int, int> get_dia_optimized(node *root)
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
// levelorderprint ----
// height -----
// diameter ----
// printatlevelk
// heightbalancedtree
// maxsubsetsum
// descendant sum

int main()
{
    // node* head = depth_build(); //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    node *head = level_build(); // 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
    // depth_traverse_preorder(head); cout << endl;
    // depth_traverse_inorder(head); cout << endl;
    // depth_traverse_postorder(head); cout << endl;
    // cout << get_height(head);
    level_order_print(head);
    cout << endl;
    cout << "diameter is: " << get_diameter(head);
    return 0;
}
