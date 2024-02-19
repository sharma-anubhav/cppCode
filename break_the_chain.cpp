#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
    }
};

node *breakChain(node *head)
{
    // Complete this method
    unordered_set<node *> s;
    s.insert(head);

    node *temp = head;
    while (1)
    {
        if (s.find(temp->next) != s.end())
        {
            temp->next = NULL;
            break;
        }
        else
        {
            temp = temp->next;
            s.insert(temp);
        }
    }
    return head;
}
