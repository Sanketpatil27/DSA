#include <iostream>
using namespace std;

// cretion on NOdes
struct Node
{
    int data;
    Node *next; // store next node location

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

Node *reverseList(Node *head, int k)
{
    // corner case:

    Node *curr = head;
    int cnt = 0;
    Node *next;              // to store next node location
    Node *prev = NULL;       // store prev node as next node
    Node *first = curr;      // this is to store first node for linking it to non reversed list here 1 -> 4(3->2->1->*4->5->6)

    while (curr != NULL && cnt < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        cnt++;

        curr = next;        // to jump on next node (coz we make curr->next to its previous node)
    }

    // now we have to link first node with curr node(which is not changed list's first node 4)
    first->next = curr;

    // after reversing first k nodes our k node(of original list) must be the new head (3->2->1->4->5->6) 3 is kth node here
    // now our prev pointer will on kth node which would be our head of list (coz at last curr become prev & curr = next)
    // and for next(if null in case 1->2->3->null) it will won't work for null means kth node is on prev pointer

    return prev;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *forth = new Node(4);
    Node *fifth = new Node(5);
    Node *sixth = new Node(6);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = NULL;

    cout << "Before Reversing first k nodes: ";
    printList(head);

    // new head after reversing first k nodes
    int k = 3;
    head = reverseList(head, k);

    cout << "\nAfter reversing first k nodes: ";
    printList(head);
}