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

Node *deleteTail(Node *head)
{
    // corner Case:
    // if head is null then can't delete anything or if head is only node reutrn null after deleting
    // ** In C++, calling delete on a null pointer has no effect.  so we can check both together
    if (head == NULL || head->next == NULL)
    {
        delete head;
        return NULL;
    }

    // 1.we just travel till second last Node && 2.delete last node using next pointer of second last node
    // 3.make second last node's next to Null
    Node *curr = head;
    while (curr->next->next != NULL)    // next->next coz we have to stop at second last node (don't continue loop for 2nd last node)
        curr = curr->next;

    delete curr->next;                  // curr->next is last node
    curr->next = NULL;                   // IMP coz node at next location has been deleted

    return head;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    // link created nodes, store all nodes previous location & next locations
    head->next = second;    // previous of this is already NULL, in Constructor
    second->prev = head;
    second->next = third;
    third->prev = second;   // next of this is stored null while constructing

    cout << "Before deleting last Node: ";
    printList(head);

    // time: theta 0(n) 
    // new head after deleting last node of linked list
    head = deleteTail(head);
    head = deleteTail(head);
    // head = deleteTail(head);

    cout << "\nAfter deleting last Node: ";
    printList(head);
}