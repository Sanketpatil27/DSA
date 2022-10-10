#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next; // to store the address of the next node
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct Node *deleteElement(struct Node *head, int element) {
    struct Node *ptr = head;
    struct Node *p = head->next;        // for storing the next node

    while (p->data != element && p->next != NULL)   
    {
        p = p->next;
        ptr = ptr->next;
    }
    
    if (p->data == element){
        ptr->next = p->next;
        free(p);
    }  
    else {
        cout << "Node doesn't exist" << endl;
    }

    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;

    head = (struct Node *)malloc (sizeof(struct Node));     // allocating the dynamic memory in heap
    second = (struct Node *)malloc (sizeof(struct Node));
    third = (struct Node *)malloc (sizeof(struct Node));
    forth = (struct Node *)malloc (sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = forth;

    forth->data = 4;
    forth->next = NULL;

    cout << "Before Insertion: " << endl;
    linkedListTraversal(head);

    int node = third->data;        // node to be deleted
    cout << "After Deleting " << node << " from linked List: " << endl;
    head = deleteElement(head, node);
    linkedListTraversal(head);
}