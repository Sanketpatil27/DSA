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
Node * insertAtEnd(Node *head, int val)
{
    // creating new node for inserting at last 
    Node *temp = new Node(val);
    
    // this is corner case coz if head is empty then we can't access head's data or head's next
    // if head is empty: NULL->next give segmentation falult
    // if current head is NULL(if there is no head) then we return temp as head
    if(head == NULL)
        return temp;

    // if we have provided head of list then we have to travel list till last node (not till null)
    Node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    
    // at this point we are at the last node of linked list
    // assigning last node's next to new created node
    curr->next = temp;

    // at last we reuturn the head as it is, thereby we use curr as dumy head to traverse list
    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "before inserting new node: ";
    rec(head);

    // inserting new node at end of list & return the first node as it is
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);               

    // time: O(n) coz we have to traverse till last node
    cout << "\nAfter inserting new node at end: ";
    rec(head);
}