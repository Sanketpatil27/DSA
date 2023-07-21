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

void printList(Node *head)
{
    Node *curr = head;

    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next; // assigninng next node to current node
    }
}

Node *segregateEvenOdds(Node *head)
{
    // maintain 4 variables even start & end, odd start & end

    Node *evenS = NULL;
    Node *evenE = NULL;
    Node *oddS = NULL;
    Node *oddE = NULL;

    Node *curr = head;
    while (curr != NULL)
    {
        // if even Node
        if (curr->data % 2 == 0)
        {
            // if it is first even node then only update even start
            if (evenS == NULL)
            {
                evenS = curr;
                evenE = curr;
            }
            else
            {
                evenE->next = curr;  // make curr node as next of even end
                evenE = evenE->next; // make curr node as last of even nodes
            }
        }

        else
        {
            if (oddS == NULL)
            {
                oddS = curr;
                oddE = curr;
            }
            else
            {
                oddE->next = curr; // make curr as next of prev odd end
                oddE = oddE->next; // make curr as last node of odds
            }
        }

        curr = curr->next;      // move current node
    }

    // if list only contains evens or odds then don't change head return as it is
    if(evenS == NULL || oddS == NULL)
        return head;

    // at last we link even last with odd start & odd end with NULL
    oddE->next = NULL;
    evenE->next = oddS;

    // and return even start as new head;
    return evenS;
}

int main()
{

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *forth = new Node(4);
    Node *fifth = new Node(5);

    // linking nodes
    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = NULL;

    cout << "Before differenting even odds: ";
    printList(head);

    // efficient approach time: theta(n) require 1 traversal  space: O(1)
    cout << "\nafter segregating even odds: ";
    head = segregateEvenOdds(head);
    printList(head);

    return 0;
}