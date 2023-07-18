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

void printList(Node *head)
{
    Node *curr = head;

    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next; // assigninng next node to current node
    }
}

int findMid(Node *head)
{
    // first handle corner case!!!
    // 1. first find the no. of nodes in linked list
    // 2. run the loop from 0 till (total Nodes/2) (don't count for head)
    // 3. return middle node->data;
    //    this is also work for 1 node

    if (head == NULL)
        return -1;

    Node *curr = head;
    int total = 0;
    while (curr != NULL)
    {
        curr = curr->next;
        total++;
    }

    // we have to start counting after head to reach at middle node
    int i = 0;
    curr = head;
    while (i < total / 2)
    {
        curr = curr->next;
        i++;
    }

    // now we are at middle node return its data
    return curr->data;
}

int slowFast(Node *head) {
    // we use slow & fast pointer approach. Fast moves 2 nodes at time & slow moves 1 Node at a time
    // so when fast reaches end slow reches on middle node
    // steps:
    // first hadle corner case
    // 1. initially both slow & fast points to head node
    // 2. we stop loop when either (fast == NULL or fast->next == NULL) second condition is important
    //    For if total nodes are even so, slow comes on middle when our fast pointer on last Node
    // 3. at last return slow->data (as slow remains on middle node)
    //    this is also work for 1 node
    if(head == NULL)
        return -1;

    Node *slow = head;
    Node *fast = head;
    
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // at this point our slow is on middle node, so return its data
    return slow->data;
}

int main()
{
    // Node *head = NULL;           // for chiking with null head
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *forth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);      // **for checking with even nodes

    // linking nodes
    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    // fifth->next = NULL;           // used for checking with odd length
    fifth->next = sixth;
    sixth->next = NULL;

    // Q. if there are 2 middle nodes(in case of even total nodes) then return 2nd middle node

    cout << "printing linked list: ";
    printList(head);

    // neive approach: time: O(n)   require 2 traversal
    cout << "\nMiddle Node of Linked list: " << findMid(head);
    
    // efficient solution using slow & fast pointer approach: time: O(n)    require 1 traversal
    cout << "\nUsing slow & fast: " << slowFast(head);
}