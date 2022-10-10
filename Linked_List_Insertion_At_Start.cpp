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

struct Node *insertAtStart(struct Node *head, int val){
    struct Node *ptr  = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->next = head;
    
    return ptr;         // head will be updated by this new head(ptr)
};

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;

    head = (struct Node *)malloc(sizeof(struct Node));

    head->data = 23;
    head->next = second;        // this will store address of the next node (coz next is pointer)

    second->data = 4;
    second->next = NULL;

    cout << "Before Insertion: " << endl;
    linkedListTraversal(head);
    
    cout << "After Insertion: " << endl;

    head = insertAtStart(head, 980);    // allocating head to the new inserted node
    linkedListTraversal(head);
}