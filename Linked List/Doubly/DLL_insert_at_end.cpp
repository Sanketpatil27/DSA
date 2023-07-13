#include <iostream>
using namespace std;

// cretion on NOdes
struct Node
{
    int data;
    Node *prev; // store previous node location
    Node *next; // store next node location

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

Node *insertAtTail(Node *head, int data)
{
    Node *newNode = new Node(data);

    if (head == NULL)
        return newNode;     // return new node as head

    // we have to reach at the last node to point its next to new node
    Node *curr = head;      // for traversing till last node
    while(curr->next != NULL)
        curr = curr->next;

    // we are at last node (not on null) so make last nodes next to new node && new node -> previous = curr
    curr->next = newNode;
    newNode->prev = curr;             // **very much required must do it**
    return head;                      // return head as it is
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    // link created nodes, store all nodes previous location & next locations
    head->next = second;        // previous of this is already NULL, in Constructor
    second->prev = head;
    second->next = third;
    third->prev = second;       // next of this is stored null while constructing

    cout << "Before inserting new node at Tail: ";
    printList(head);

    // new head after insertion at tail     time: O(n)
    head = insertAtTail(head, 0);
    head = insertAtTail(head, 12);

    cout << "\nAfter inserting new Node at tail: ";
    printList(head);
}