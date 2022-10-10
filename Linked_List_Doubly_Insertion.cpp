#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *prev; // pointer to store the address of the previous nodes
    struct Node *next; // pointer to store the address of the next nodes
};

void doublyTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next; // ptr will store the next node (coz ptr->next storing the address of next node)
    }
}

struct Node *insertAtStart(struct Node *head, int val)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    
    ptr->prev = NULL;
    ptr->data = val;
    ptr->next = head;

    struct Node *p = head;
    p->prev = ptr;

    return ptr;     // returning ptr as head (must)
};

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // allocating memory in heap (dynamic memory)
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL; // stored the addres of previous node(here it is NULL)
    head->data = 1;
    head->next = second; // storing address of next node(here it is second)

    second->prev = head;
    second->data = 2;
    second->next = third;

    third->prev = second;
    third->data = 3;
    third->next = NULL;

    cout << "Before Insertion: " << endl;
    doublyTraversal(head);

    cout << "After Insertion At head: " << endl;
    head = insertAtStart(head, 79);
    head = insertAtStart(head, 3459);         // another insertion
    doublyTraversal(head);
}