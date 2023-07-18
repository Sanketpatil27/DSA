#include <iostream>
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
    // checking this corner case seperately coz using do while this will access NULL's data & next without checking
    // it is null or not
    if(head == NULL)
        cout << "empty list!" << endl;

    // use temp node for traversing and stop when we again see head 
    // using do while coz we have to first print data of first node & then go to next node without checking condition
    Node *curr = head;             
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while(curr != head);
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // link last node's next to head
    head->next->next->next = head;

    // if there is only on node that is head it's next should point itself
    // head->next = head;

    cout << "Circular Linked List: ";
    printList(head);
}