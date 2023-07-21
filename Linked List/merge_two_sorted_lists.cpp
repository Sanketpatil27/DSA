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

Node *mergeSorted(Node *list1, Node *list2)
{
    // if any of the list is null means no need to merge them
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    // first we have to handle setting head explicitly
    // we maintain head & tail for new modified merged list
    Node *head;
    Node *tail;

    // set head to one of the list head which has smaller  dataue
    // after setting head we have to move the list which head is selected for head in new List
    if (list1->data < list2->data)
    {
        head = list1;
        list1 = list1->next;
    }
    else
    {
        head = list2;
        list2 = list2->next;
    }

    tail = head;

    // now traverse both lists till end
    while (list1 != NULL && list2 != NULL)
    {
        // now we don't set we only modify our modified list's tail
        if (list1->data < list2->data)
        {
            tail->next = list1;
            list1 = list1->next;
            tail = tail->next; // we have to move on new tail
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
            tail = tail->next;
        }
    }

    // after loop any one of the list will be ended and remaining list we simply add as it is
    // after the tail coz there are no nodes in second list to compare with
    if (list1 == NULL)
        tail->next = list2;
    else
        tail->next = list1;

    // at last return head of modified list
    return head;
}


int main()
{
    // list1
    Node *head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);

    // list2
    Node *head2 = new Node(5);
    head2->next = new Node(25);
    head2->next->next = new Node(35);

    // time: O(n+m) in worst case space: O(1)
    // we have to modify 1 list, 
    cout << "After merging both sorted lists: ";
    head1 = mergeSorted(head1, head2);
    printList(head1);
}