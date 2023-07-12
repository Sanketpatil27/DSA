#include <iostream>
using namespace std;

// cretion on NOdes
struct Node
{
    int data;
    Node *next;     // store next node location

    Node(int val)
    {
        data = val;
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

    // we store previous node & next node pointer
    // use this node to store next of curr before changing it
    Node *prevNode = NULL;
    Node *next = NULL;      
    Node *curr = head;
    

    while(curr != NULL) {
        next = curr->next;
        curr->next = prevNode;  // swap nodes
        
        prevNode = curr;

        // we changed next pointer so its now stored in next node
        curr = next;
    }

    // 1 <- 2 <- 3 <- NULL (we are at here 'NULL')
    // at this point we are at NULL & prevNode at last node 
    // so return last node as head
    return prevNode;
}

int main()
{
    // I/p: 10 -> 20 -> 30  o/p: 30 -> 20 -> 10  
    
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    // link created nodes, store all nodes previous location & next locations
    head->next = second;        // previous of this is already NULL, in Constructor
    second->next = third;

    cout << "Before Reversing Linekd list: ";
    printList(head);

    // new head after reversing linked list    time: O(n)       space: O(1)
    head = reverseList(head);
    // head = reverseList(head);       // it will make reversed again original

    cout << "\nAfter reversing linked list: ";
    printList(head);
}