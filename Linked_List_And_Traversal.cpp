#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next; // pointer of next to store the next node address(type of node)
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;            // updating the address of pointer to get the next node
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;

    // allocate memory for Nodes in linked list in heap(dynamic memory allocation)
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    forth = (struct Node *)malloc(sizeof(struct Node));

    // link first node to second node
    head->data = 7;
    head->next = second;

    // link second node to third node
    second->data = 56;
    second->next = third;

    // link third to forth node
    third->data = 23;
    third->next = forth;

    // terminate the list at the third node
    forth->data = 989;
    forth->next = NULL;

    linkedListTraversal(head);

    return 0;
}