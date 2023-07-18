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
    if (head == NULL)
        cout << "empty list!" << endl;

    // use temp node for traversing and stop when we again see head
    // using do while coz we have to first print data of first node & then go to next node without checking condition
    Node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
}

Node *insertAtTail(Node *head, int data)
{
    // 1: create new node for newTail && handle some important corner cases
    // 2: reach till last node
    // 3: make newTail->next = head && last node->next = newTail
    // 4: return head as it is (if head is not null)

    Node *newTail = new Node(data);

    // corner case
    if (head == NULL)
    {
        newTail->next = newTail;
    }
    else
    {
        Node *curr = head;
        while (curr->next != head)
            curr = curr->next;

        // now we are at last node perform step 3
        newTail->next = head;         // to maintain circular pattern
        curr->next = newTail;
    }

    return head;
}

Node *efficient(Node *head, int data)
{
    // approach: 
    // we connect newTail with second and disconnect connection between head & second node
    // and we swap data of newTail and head; so we make newTail as head & head as newTail & return newTail as new head node
    // 1: create new node as newTail  handle same corner case as up approach
    // 2: make newTail->next = head->next && make head->next = newTail 
    // 3: swap data of head & newTail
    // 4: return newTail as new head (we swap data and make head as tail newTail as head)

    // step 1:
    Node *newTail = new Node(data);

    // corner case:
    if (head == NULL)
    {
        // make newHead->next = newHead & return
        newTail->next = newTail;
        return newTail;
    }

    // from step 2: 
    newTail->next = head->next;
    head->next = newTail;

    // for step 3: data swapping
    int temp = head->data;          // to hold head original data
    head->data = newTail->data;
    newTail->data = temp;

    // step 4:
    return newTail;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // link last node's next to head
    head->next->next->next = head;

    cout << "Linked List Before insertion at tail: ";
    printList(head);

    // neive approach:
    // new head after inserting new node at end O(n)
    head = insertAtTail(head, 23);

    // efficient approach: time: O(1)
    head = efficient(head, 67);

    cout << "\nLinked List after insertion at tail: ";
    printList(head);
}