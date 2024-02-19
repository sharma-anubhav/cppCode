#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <limits.h>
using namespace std;

struct Node
{
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

struct Node2
{
    int a;
    Node2 *next;

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

    void print_list_struct()
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
    head4.print_list_struct();
}

///////****** QUESTION ***********
// why do we pass node
