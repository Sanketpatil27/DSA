#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

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


Node *deleteHead(Node *head)
{
    // if head is null then can't delete anything or if head is only node reutrn null after deleting
    // ** In C++, calling delete on a null pointer has no effect.  so we can check both together
    if (head == NULL || head->next == NULL)
    {
        delete head;
        return NULL;
    }

    // we just have to return the head -> next as new head;
    // but we also have to delete head node from memory & change previous of new head to NULL
    Node *temp = head;
    head = head->next;              // move on pointer make this new head and make prev as NULL
    head->prev = NULL;              // head has to be deleted so make its prev as null

    delete temp;                    // delete head from memory

    return head;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    // link created nodes, store all nodes previous location & next locations
    head->next = second; // previous of this is already NULL, in Constructor
    second->prev = head;
    second->next = third;
    third->prev = second; // next of this is stored null while constructing

    cout << "Before deleting head: ";
    printList(head);

    // time: theta 0(1) coz doing constant no. of operations;  space: O(1)
    // new head after deleting head of linked list    
    head = deleteHead(head);
    // head = deleteHead(head);      

    cout << "\nAfter deleting head: ";
    printList(head);
}