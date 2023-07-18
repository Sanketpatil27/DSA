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

// we have to return the head after inserting new node at end of the list
Node * deleteHead(Node *head)
{
    // if head is null then can't delete anything
    if(head == NULL)
        return NULL;

    // we just have to return the head -> next as new head; 
    // but we also have to delete head node from memory
    Node *temp = head->next;
    delete head;

    return temp;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "before deleting head: ";
    rec(head);

    // new head after deleting head
    head = deleteHead(head);
    // head = deleteHead(head);               

    // time: O(1)
    cout << "\nAfter deleting head: ";
    rec(head);
}