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

// we have to return the head after inserting new node at position of the list
Node * insertAtPos(Node *head, int val, int position)
{
    // creating new node for inserting at last 
    Node *newNode = new Node(val);
    
    // if insertion position is 1 then we put new nodes next to head and return newNode as head
    if(position == 1) {
        newNode->next = head;
        return newNode;
    }


    Node *curr = head;

    // we run till position-2, not position-1 coz if we run till position - 1 we run till previous node of position
    // and then in loop it will go to next of it means on the position so we have to use positon-2 so that we stop at
    // previous node of position
    for(int cnt = 1; cnt <= position-2 && curr != NULL; cnt++) 
        curr = curr->next;
    
    // if current not reaches till null means position is beyong the size of the linked list 
    // and we can't isnert at that position so return head as it is
    if(curr == NULL) 
        return head;
    
    // we don't want to lose address of node at that position so store it in next of the new node
    // we stoped before position so we put current node's next to new node
    newNode->next = curr->next;
    curr->next = newNode;

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

    // inserting new node at given position of list & return the first node as it is
    head = insertAtPos(head, 1, 2);
    head = insertAtPos(head, 2, 4);               
    head = insertAtPos(head, 200, 1);               

    // time: O(n) in worst case we have to traverse till last node otherwise O(position)
    cout << "\nAfter inserting new node at position: ";
    rec(head);
}