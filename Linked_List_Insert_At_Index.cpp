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

struct Node *insertAtIndex(struct Node *head, int index, int val)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;

    struct Node *p = head;

    int i = 0;
    while (i != index - 1)
    { 
        p = p->next;        // p will stand at before the insertion index
        i++;
    }

    ptr->next = p->next; // we have to store address of the next node(which is before the insertion)
    p->next = ptr;

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

    cout << "Before Insertion: " << endl;
    linkedListTraversal(head);

    int index = 4;
    cout << "After Insertion at index " << index << ": " << endl;
    head = insertAtIndex(head, index, 789);
    linkedListTraversal(head);
}