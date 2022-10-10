#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next; // to store the address of the nodes
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
};

struct Node *deletingFirstNode(struct Node *head)
{
    // first method
    struct Node *ptr = head;
    ptr->next = head->next;     // all head data(data & address of next node) will be copied in ptr
    head = ptr->next;           // now updating the head with the next node
    free(ptr);                  // and free(delete) the memory of previous head node stored in ptr

    // second method(easy)
    // head = head->next;           // updating the head with the next node
    return head;
};

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    forth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second; // this will store address of the next node (coz next is pointer)

    second->data = 2;
    second->next = third; 

    third->data = 3;
    third->next = forth; 

    forth->data = 4;
    forth->next = NULL; 

    cout << "Before Insertion: " << endl;
    linkedListTraversal(head);

    cout << "After Insertion: " << endl;

    head = deletingFirstNode(head); // after deleting head new head will be sored
    linkedListTraversal(head);
}