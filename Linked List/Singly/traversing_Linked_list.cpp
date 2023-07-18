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

// traversing using recursion
void rec(Node *head)
{
    if (head == NULL)
        return;

    cout << head->data << " ";
    rec(head->next);
}

// traversing normally
void printList(Node *head)
{
    // note: 
    // this head is function variable head not same as main() function variable head it is copied as normal int, float values
    // so if we don't use curr then also it not modify original head from main() function 
    Node *curr = head;

    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next; // assigninng next node to current node
    }
}

int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // using normal function take time: O(n) where n is no.of nodes & space: O(1)
    cout << "print using normal function: ";
    printList(head);

    // using recursion take time: O(n) where n is no.of nodes & space: O(n) for recursive n calls
    cout << "\nprint using recursive function: ";
    rec(head);

    return 0;
}