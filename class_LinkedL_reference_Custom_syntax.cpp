#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <limits.h>
using namespace std;

// same thing as struct
// The only difference being it can be used for inheritence etc
// Class is in heap whereas normal (without references, very basic) struct are in stack.
// Class has its data variables by defauly private where as struct has public.

class Node
{
public:
    int a;
    Node *next;
};

void push_front(Node **head, int value)
{
    struct Node *new_node = new Node;
    new_node->a = value;
    new_node->next = *head;
    *head = new_node;
}

void push_front2(Node *head, int value)
{
    // call using reference in main()
    // probably will give error because Node* is head and &head will be Node**
}

void push_front3(Node *&head, int value)
{
    // reference
    struct Node *new_node = new Node;
    new_node->a = value;
    new_node->next = head;
    head = new_node;
}

void print_list(Node *head)
{
    // need to check head = NULL case in begining
    while (head->next != NULL)
    {
        cout << head->a << " -> ";
        head = head->next;
    }
    cout << head->a;
    cout << endl;
}

class Node2
{
    int a;
    Node2 *next;

public:
    Node2() {}
    Node2(int value)
    {
        a = value;
        next = NULL;
    }

    void insert_front(int data)
    {
        // very IMP. This pointer is a constant
        // hence we cannot make it the left operand where there should be a variable
        // hence inserting in front is having issues in methods.
        struct Node2 *new_node = new Node2;
        new_node->a = data;
        new_node->next = this;
        // this = new_node; // This Lines gives the error
    }
    void insert_back(int data)
    {
        struct Node2 *new_node = new Node2;
        new_node->a = data;
        new_node->next = NULL;

        Node2 *temp = this;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void print_list_class()
    {
        Node2 *temp = this;
        while (temp->next != NULL)
        {
            cout << temp->a << " -> ";
            temp = temp->next;
        }
        cout << temp->a;
        cout << endl;
    }
};

void reverse_iterative(Node *&head)
{
    if (head->next == NULL)
    {
        return;
    }
    else
    {
        Node *cur;
        Node *back;
        Node *forward;
        cur = head->next;
        head->next = NULL;
        back = head;

        while (cur != NULL)
        {
            forward = cur->next;
            cur->next = back;
            back = cur;
            cur = forward;
        }
        head = back;
    }
    return;
}

Node *recursive_reverse(Node *head)
{
    if (head->next == NULL)
    {
        return head;
    }

    Node *shead = recursive_reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return shead;
}

Node *k_reverse(Node *old_head, int k)
{
    if (old_head == NULL)
        return old_head;
    Node *prev = old_head;
    Node *cur;
    Node *forward;
    cur = old_head->next;
    int i = 0;

    while (i < (k - 1) and cur != NULL)
    {
        forward = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forward;
        i++;
    }

    if (cur == NULL)
    {
        old_head->next = NULL;
        return prev;
    }

    old_head->next = k_reverse(cur, k);

    return prev;
}

Node *reverse_iterative_2(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return head;
    }

    Node *cur;
    Node *prev;
    Node *next;
    cur = head->next;
    head->next = NULL;
    prev = head;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

int main()
{
    Node *head = NULL;
    // sending reference as function expects a address to Node* and "&" sends pointer/address
    // i.e Node**
    push_front(&head, 1);
    push_front(&head, 2);
    push_front(&head, 3);
    print_list(head);

    // Node* head2 = NULL;
    // push_front2(&head2, 1);
    // push_front2(&head2, 2);
    // print_list(head);

    Node *head3 = NULL;
    // Function expects a node* and it will automatically make it a reference with & in argument
    push_front3(head3, 1);
    push_front3(head3, 2);
    push_front3(head3, 3);
    print_list(head3);

    // Using methods instead of outside functions.
    Node2 head4(1);
    head4.insert_back(2);
    head4.print_list_class();
}

///////****** QUESTION ***********
// why do we pass node
