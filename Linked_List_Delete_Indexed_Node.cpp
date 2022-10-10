#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next; // to store the next node address
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct Node *deletionAtIndex(struct Node *head, int index)
{
    // struct Node *ptr;
    // struct Node *p = head;

    // int i = 0;
    // while (i != index - 1)
    // { 
    //     p = p->next;        // p will stand at before the insertion index
    //     i++;
    // }

    // // we have to store address of the next node which is after the deletion index(which is before the insertion)
    // ptr = p->next;          // this will store the deleting indexed node
    // cout << "Deleted Node: " << ptr->data << endl;
    // ptr = ptr->next;        // this will store the the node after the deleting node
    // p->next = ptr;


    // (method 2nd) or we can also use like this (simple way)->
    struct Node *ptr = head->next;
    struct Node *p = head;

    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        ptr = ptr->next;
    }

    p->next = ptr->next;
    free(ptr);

    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;

    head = (struct Node *)malloc(sizeof(struct Node)); // allocation dynamic memory to nodes
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    forth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second; // storing address of next node

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = forth;

    forth->data = 4;
    forth->next = NULL;

    cout << "Before Deletion: " << endl;
    linkedListTraversal(head);

    int index = 2;
    cout << "After Deletion at index " << index << ": " << endl;
    head = deletionAtIndex(head, index);
    linkedListTraversal(head);
}