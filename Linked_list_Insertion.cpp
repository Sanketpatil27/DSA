#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next; // next used for to save the next node address
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next; // to update the address of node to next node
    }
}

struct Node  *insertionAtFirst(struct Node *head, int val)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));    
    ptr->data = val;
    ptr->next = head;       // this will allocate the address to the head of main node

    return ptr;
};


struct Node  *insertionAtIndex(struct Node *head, int val, int index)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node)); 
    struct Node * p = head;         // for storing next node address
    int i = 0;

    while (i != index-1)        // first node already have address of next node
    {
        p = p->next;
        i++;
    }                       // now ptr will stand at before the index of insertion

    ptr->data = val;
    ptr->next = p->next;    // thid will connect ptr to the original node(index) before insertion
    p->next = ptr;          // this will change the original index to the new insertion index

    return head;            // optional
};

// struct Node *insertInBetween(struct Node *index, struct Node *previous, int val)
// {       
//     struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
//     previous->next = ptr;
//     ptr->data = val;
//     ptr->next = index;
//     return ptr;
// };             // inserted manually


struct Node *insertAtEnd(struct Node *head, int val) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;

    struct Node *p = head;      //  TO store the next node address

    while(p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;

    // allocating memory for nodes to the linked list in the heap(dynamic memory)
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    forth = (struct Node *)malloc(sizeof(struct Node));

    // link first node to the second node
    head->data = 1;
    head->next = second;

    // link second to the third
    second->data = 2;
    second->next = third;

    // link third to the forth
    third->data = 3;
    third->next = forth;

    // link forth to NULL
    forth->data = 4;
    forth->next = NULL;

    cout << "Before Insertion: " << endl;
    linkedListTraversal(head);

    // insert at first
    // head = insertionAtFirst(head, 34);
    
    // Insert node at position second       (created manually)
    // third = insertInBetween(third, second, 234);
    
    // Insert node at Index ,parameters: head node, data, index
    head = insertionAtIndex(head, 234, 1);

    // insert at end
    insertAtEnd(head, 7899);

    cout << "After Insertion: "  << endl;
    linkedListTraversal(head);
}