#include <bits/stdc++.h>
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

void rec(Node *head)
{
    if (head == NULL)
        return;

    cout << head->data << " ";
    rec(head->next);
}

// we have to return the head after deleting last node
Node * deleteTail(Node *head)
{
    // corner cases
    // if head is null then can't delete anything
    if(head == NULL)
        return NULL;

    // head is only node
    if(head->next == NULL) {
        delete head;
        return NULL;
    }
    // we just have to return node before the last node
    // but we also have to delete last node from memory
    Node *curr = head;

    // loop till second last position
    while(curr->next->next != NULL)
        curr = curr->next;

    // delete the last node which is next of the second last node
    delete curr->next;

    // important part here is we have to make curr->next null otherwise program goes in infinite recursion while printing
    curr->next = NULL;

    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "before deleting head: ";
    rec(head);

    // new head after deleting tail of linked list
    head = deleteTail(head);
    // head = deleteTail(head);               

    // time: O(n)
    cout << "\nAfter deleting head: ";
    rec(head);
}