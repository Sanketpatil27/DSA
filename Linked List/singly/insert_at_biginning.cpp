#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void rec(Node *head)
{
    if (head == NULL)
        return;

    cout << head->data << " ";
    rec(head->next);
}

// function return type should as the type of the node coz we are returning the node value
Node *insertAtHead(Node *head, int val)
{
    Node *temp = new Node(val);

    // assing current head address to our new inserted temp
    temp->next = head;

    // return inserted node
    return temp;
}

int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "before inserting new node: ";
    rec(head);

    // inserting new node at head & passing current head & data
    // assigning new inserted head node to current head
    head = insertAtHead(head, 1);
    head = insertAtHead(head, 2);               

    // time: O(1)
    cout << "\nAfter inserting new node at start: ";
    rec(head);
}