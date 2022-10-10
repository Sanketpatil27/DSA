#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next; // to store address of next node
};

void circularTraversal(struct Node *head)
{
    struct Node *ptr = head;

    // do while loop always executes at least once, So, then we update the ptr to head to ptr->next(Which is second node)
    do      // used do while to print all nodes of the linked list
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node)); // allocating dynamic memory in the heap
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second; // storing address of next node

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = head;

    circularTraversal(head);
}