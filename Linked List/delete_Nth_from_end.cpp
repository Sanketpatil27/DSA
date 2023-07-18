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


Node* removeNthFromEnd(Node* head, int n) {
    //    handle corner cases like (head == NULL or head->next == NULL && n == 1) and 
    //    if (size-n == 0) that is if we have to delete head node
    // 1. find size of linked list  (take first example)
    // 2. then we again traverse list & stop at (size - n)th node (3 in 1st example)
    // 3. then we make (3->next) =  (4->next) (4 has to be deleted)
    // 4. return head at last

    // corner case n atleast 1 (for clearing 2nd condition)
    if(head == NULL || head->next == NULL)
        return NULL;

    int size = 0;
    Node *curr;

    // step 1:
    for(curr = head; curr != NULL; curr = curr->next)
        size++;

    // another corner case
    // if we have to delete head node then this should be added; for case like
    // [1,2] n = 2  then reutrn next of head as new head
    if(size - n == 0) {
        Node *temp = head;
        head = head->next;      // move heade to second node
        delete temp;            // delete head from memory

        return head;      
    }

    // step 2:
    curr = head;        
    // start from 1 coz we are already at head, so one count goes in this
    for(int i = 1; i < (size-n); i++) 
        curr = curr->next;

    // step 3:
    // here our curr stopped on node 3;
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;        // remove nth node from last from memory

    return head;
}

Node *slowFast(Node *head, int n) 
{
    // we use 2 poninters approach here
    // handle corner case of head == NULL or head->next == NULL 
    // here also we have to handle the case if we have to delete head node
    // 1. we move fast 'n' positions ahead of head (n always within size)
    // 2. start slow pointer from head
    // 3. movef both pointers at same speed of 1 node at time. we stop when fast reaches at last node, so then 'slow' 
    //    will be at previous node of nth node (coz fast is ahead of n nodes)
    // 4. revome next of slow (which is nth node) from memory
    // 5. return head

    // if there is only 1 node n must be 1
    if(head == NULL || head->next == NULL) {
        delete head;
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;      // we have to move 'fast' pointer 'n' nodes ahead

    for(int i = 0; i < n; i++)
        fast = fast->next;

    
    // corner case:
    // here if our fast pointer reches 'NULL' after putting in n nodes ahead means we have to  delete head node
    if(fast == NULL) {
        Node *temp = head;
        head = head->next;      // make second node as head
        delete temp;            // delete head node from memory

        return head;      // return second node as head
    }

    // we have to stop at previous node of nth from last
    while (fast->next != NULL)  
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    // now we are at prev node of nth node from last (at 3 in example)
    Node *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;        // delete nth node from last

    return head;
}

int main()
{

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *forth = new Node(4);
    Node *fifth = new Node(5);

    // linking nodes
    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = NULL;         

    cout << "Before deleting nth node from last: ";
    printList(head);

    // 1 <= n <= size of list
    int n = 5;

    // head after removing nth from last
    // neive approach: time: O(n)   require 2 traversal
    // head = removeNthFromEnd(head, n);
    // cout << "\nAfter deleting nth node from last: ";
    // printList(head);

    // efficient approach time: O(n) require 1 traversal using slow and fast pointers
    head = slowFast(head, n);
    cout << "\nEfficient: After deleting nth node from last: ";
    printList(head);

    return 0;
}