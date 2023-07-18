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

Node *insertAtHead(Node *head, int data)
{
    // 1: create new node for newHead && handle some important corner cases
    // 2: make next of newHead -> head;
    // 3: make last node's->next = newHead
    // 4: return newHead as head

    Node *newHead = new Node(data);

    // corner case:
    if (head == NULL)
    {
        // make newHead->next = newHead & return
        newHead->next = newHead;
        return newHead;
    }

    // from step 2:
    newHead->next = head;

    // for step 3: we have to reach last node
    Node *curr = head;
    while (curr->next != head)
        curr = curr->next;

    // now we are at last node, so make its next to newHead
    curr->next = newHead;

    return newHead;
}

Node *efficient(Node *head, int data)
{
    // 1: create new node as newHead  handle same corner case as up approach
    // 2: make newHead->next = head->next && make head->next = newHead
    // 3: swap data of head & newHead
    // 4: return head as it is as we have swapped data, that's all!

    // step 1:
    Node *newHead = new Node(data);

    // corner case:
    if (head == NULL)
    {
        // make newHead->next = newHead & return
        newHead->next = newHead;
        return newHead;
    }

    // from step 2: store next node of head
    newHead->next = head->next;         
    head->next = newHead;

    // for step 3: swap data of both head & newHead
    int temp = head->data;                  // to hold head original data
    head->data = newHead->data;
    newHead->data = temp;
    
    // step 4:
    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // link last node's next to head
    head->next->next->next = head;

    cout << "Linked List Before insertion at head: ";
    printList(head);

    // new head after inserting new node at head
    // this is neive implementation time: O(n) as we have to traverse till last node
    head = insertAtHead(head, 23);

    // efficient approach: time: O(1)
    head = efficient(head, 67);

    cout << "\nLinked List after insertion head: ";
    printList(head);
}