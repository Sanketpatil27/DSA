#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
};

struct Node *insertAtLast(struct Node *head, int val)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    
    ptr->data = val;
    ptr->next = NULL;
    p->next = ptr;
};

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;

    head = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second; // this will store address of the next node (coz next is pointer)

    second->data = 2;
    second->next = NULL;

    cout << "Before Insertion: " << endl;
    linkedListTraversal(head);

    cout << "After Insertion: " << endl;

    insertAtLast(head, 980);
    linkedListTraversal(head);
}