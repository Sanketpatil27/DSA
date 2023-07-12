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

Node *insertAtBegin(Node *head, int data)
{
    Node *newNode = new Node(data);

    if (head == NULL)
        return newNode; // return new node as head

    // make newNode's next as given head  && head's previous as newNode & return newNode as head
    newNode->next = head;
    head->prev = newNode;

    return newNode;
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

    cout << "Before inserting new Head: ";
    printList(head);

    // new head after insertion  time: O(1)
    head = insertAtBegin(head, 0);
    head = insertAtBegin(head, 12);

    cout << "\nAfter inserting new Head: ";
    printList(head);
}