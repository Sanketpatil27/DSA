#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next; // to store the address of nodes
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next; // storing next node data in ptr
    }
}

struct Node *deleteEndNode(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *p = head->next; // storing next node(second) to the p

    // when p(which stores second node) reaches NULL, ptr will be before the last node

    // checking p->next coz , we have to check the next address of p if it is NULL then don't go in while(thats why we check next node address before going to while loop)
    while (p->next != NULL)
    {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = NULL; // update the ptr address from last node to the NULL
    return head;
};

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node)); // allocation dynamic memory to the nodes
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second; // saving the address of the next node

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    cout << "Before Deletion: " << endl;
    linkedListTraversal(head);

    cout << "After Deleting Last Node: " << endl;

    head = deleteEndNode(head);

    linkedListTraversal(head);
}