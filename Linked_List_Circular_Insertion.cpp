#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next; // to store address of the next node
}; 


void circularTraversal(struct Node *head)
{
    struct Node *ptr = head;

    // used do while loop to print all the nodes, do while executes at least once
    // so we update the ptr to head to ptr->next(which is second node)
    do
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insertAtStart(struct Node *head, int val)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;

    struct Node *p = head;
    while (p->next != head) 
    {
        p = p->next;
    }
    // at this point p will be at last node
    // now last node stores address of the new first node
    p->next = ptr;
    ptr->next = head;
    
    return ptr;         // returned pointer as first node
};

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second; // this will store address of the next node (coz next is pointer)

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = head;
     
    cout << "Before Insertion: " << endl;
    circularTraversal(head);

    cout << "After Insertion: " << endl;

    head = insertAtStart(head, 980); // allocating head to the new inserted node
    head = insertAtStart(head, 65); // adding another head
    circularTraversal(head);
}