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

int neive(Node *headA, Node *headB)
{
    // we use unorderd set, first store all nodes from A list and then
    // while traversing list B if we find node already present means that is the intersection
    // point of both linked lists

    unordered_set<Node *> s;

    Node *curr = headA;
    while (curr != NULL)
    {
        s.insert(curr);
        curr = curr->next;
    }

    // now traverse list B and find intersection point
    curr = headB;
    while (curr != NULL)
    {
        if (s.find(curr) != s.end())
            return curr->data;

        curr = curr->next;
    }

    // if there is no intersection point
    return -1;
}

int getIntersectionNode(Node *headA, Node *headB)
{

    // 1. we count nodes of both lists (c1 & c2)
    // 2. we cut bigger list to make it same size of small list, by traversing bigger list
    //    abs(c1-c2) times
    // 3. now traverse both list's simulteneously until we found common node between them

    int c1 = 0;
    int c2 = 0;

    Node *a = headA;
    Node *b = headB;

    while (a != NULL)
    {
        c1++;
        a = a->next;
    }

    while (b != NULL)
    {
        c2++;
        b = b->next;
    }

    // now we find bigger list and cur down it by abs(c1-c2) nodes
    // reseting pointers to default for next operations
    a = headA;
    b = headB;

    // if A list is bigger
    if (c1 > c2)
    {
        int d = c1 - c2;

        // move list A d nodes ahead
        for (int i = 0; i < d; i++)
            a = a->next;
    }

    // if B list is bigger
    else if (c2 > c1)
    {
        int d = c2 - c1;

        // move list A d nodes ahead
        for (int i = 0; i < d; i++)
            b = b->next;
    }

    // now we traverse both lists simulteneously
    // as now both list size is same so we can only add one condition in while loop
    while (a != NULL)
    {
        // first check coz new list can begin from list 1 itself
        // first list:  1->null
        // second list: ^ this is starting of second list; both are same here!
        if (a == b)
            return a->data;

        a = a->next;
        b = b->next;
    }

    // we come here means there is no intersection
    return -1;
}

int main()
{
    // first list
    Node *headA = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *forth = new Node(4);
    Node *fifth = new Node(5);

    // linking nodes
    headA->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = NULL;

    // second list
    Node *headB = new Node(7);

    // *** linking with other  part, here intersection point is third node
    headB->next = third;

    cout << "listA: ";
    printList(headA);

    cout << "\nlistB: ";
    printList(headB);

    // neive approach: time: O(m+n) (m is size of A n is of B) space: O(m) (we only store A)
    cout << "\nIntersection point of two lists is: " << neive(headA, headB);

    // // efficient appraoch: time: O(m+n) (m is size of A & n is size of B) space: O(1)
    cout << "\nIntersection point of two lists is: " << getIntersectionNode(headA, headB);

    return 0;
}