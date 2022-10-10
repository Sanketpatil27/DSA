#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next; // to store the address of the next node
};

void circularTraversal(struct Node *head)
{
    struct Node *ptr = head;

    do
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *deleteLast(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *p = head->next;        // p is storing the second node

    while (p->next != head)
    {
        p = p->next;
        ptr = ptr->next;
    }
    // at this point p is at the last node
    // and ptr is at the second last position,
    // so ptr will store the address of head node rather than last node
    ptr->next = p->next;
    
    return head;
};


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;

    // allocation memory in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    forth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;       // stored the memory in the heap(dynamic memory)
    head->next = second; // this will store address of the next node (coz next is pointer)

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = forth;

    forth->data = 4;
    forth->next = head;


    cout << "Before Deletion : " << endl;
    circularTraversal(head);

    cout << "After Deletion: " << endl;

    head = deleteLast(head); // allocating head to the new inserted node
    // head = deleteLast(head); // deleting another end node
    circularTraversal(head);
}