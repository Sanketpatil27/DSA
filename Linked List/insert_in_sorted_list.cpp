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
Node * sortedInsert(Node *head, int data)
{
    // check for corner case as head is null or head->data >= data 
    // 1. create new node & check corner cases
    // 2. loop till last node && curr->next->data < given data
    // 3. check every node's next node data with given data if >= given data then stop loop
    //    insert new Node after curr node
    // 4. if we reach at last node or previous node of node which > given data
    // 5. return head as it is
    
    
    // step 1:
    Node *newNode = new Node(data);
    
    
    // corner cases:
    if(head == NULL)
        return newNode;     // then reutrn head as it is
        
    // if we have to insert at head (data <= head->data)
    if(head->data >= data) {
        newNode->next = head;       // make head as new node's next
        return newNode;             // return newNode as head
    }
    
    
    // step 2:
    // now we check from head node that it's next node's data >= given data 
    // checked for head seperately
    Node *curr = head;
    while(curr->next != NULL && curr->next->data < data)
        curr = curr->next;
    
    // we are here means either curr at last node or curr node is previous node of the node which is > data
    //means we have to insert new node here it can be tail
    newNode->next = curr->next;         // first maintain nodes reference of curr node's next node
    curr->next = newNode;               // then modify curr node's next as new Node
    
    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "before inserting new node: ";
    rec(head);

    //  we have to insert in position that remains list sorted

    head = sortedInsert(head, 12);               

    // time: O(n) in worst case we have to traverse till last node otherwise O(position)
    cout << "\nAfter inserting new node: ";
    rec(head);
}