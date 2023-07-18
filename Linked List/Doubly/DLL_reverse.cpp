#include <iostream>
using namespace std;

// cretion on NOdes
struct Node
{
    int data;
    Node *prev;     // store previous node location
    Node *next;     // store next node location

    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }   
}

Node *reverseList(Node *head)
{
    // corner case: 
    // if list head is null or head is only node then we just return head as it is
    if(head == NULL || head->next == NULL)
        return head; 

    // **we will change node's next to previous & previous to nodes next (swap the nodes addresses to reverse list)

    Node *curr = head;
    // we can't do swapping directly we need temporary node for storing their prev before changeing it to ->next
    Node *prev = NULL;               // used to store previous pointer of nodes

    while (curr != NULL) 
    {
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;          // we have stored prev in temp

        curr = curr->prev;          //  whatever was next now become previous; we have changed its next so we have to go it in prev node 
    } 

    // 10 <- 20 <- 30 <- NULL (we are at here 'NULL')
    // at this point our curr is at NULL (can't access it's previous for returning as head)
    // but our prev (temp node) will having on the Node 20 (when curr on 30 its prev is 20)
    // so we can return prev->prev (coz 30 is now 20's previousd) to send 30 as head
    return prev->prev;
}

int main()
{
    // I/p: 10 -> 20 -> 30  o/p: 30 -> 20 -> 10   (assume this as duobly linked list)
    
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    // link created nodes, store all nodes previous location & next locations
    head->next = second;        // previous of this is already NULL, in Constructor
    second->prev = head;
    second->next = third;
    third->prev = second;       // next of this is stored null while constructing

    cout << "Before Reversing Linekd list: ";
    printList(head);

    // new head after reversing linked list    time: O(n)       space: O(1)
    head = reverseList(head);
    // head = reverseList(head);       // it will make reversed again original

    cout << "\nAfter reversing linked list: ";
    printList(head);
}