#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *prev;          // pointer to store the address of the previous nodes
    struct Node *next;          // pointer to store the address of the next nodes
};


// Traverse in straight direction
void doublyTraversal(struct Node *ptr){
    while (ptr != NULL) {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;        // ptr will store the next node (coz ptr->next storing the address of next node)
    }
}


// Traverse in reverse direction
void doublyTraversalRev(struct Node *ptr){

    // Method 1. with last node (means ptr = third)-->
    // while (ptr != NULL) {
    //     cout << "Element: " << ptr->data << endl;
    //     ptr = ptr->prev;        // ptr will store the next node (coz ptr->next storing the address of next node)
    // }


    // Method 2. with head node-->
    while (ptr->next != NULL) {
        ptr = ptr->next;        // ptr will store the next node (coz ptr->next storing the address of next node)
    }

    // at this point ptr will at the last node not on the null node(means ptr = last node data)
    while (ptr != NULL) {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->prev;        // ptr will store the next node (coz ptr->next storing the address of next node)
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // allocating memory in heap (dynamic memory)
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;      // stored the addres of previous node(here it is NULL)
    head->data = 1;
    head->next = second;    // storing address of next node(here it is second)

    second->prev = head;
    second->data = 2;
    second->next = third;

    third->prev = second;
    third->data = 3;
    third->next = NULL;

    cout << "Straight Traversal: " << endl;
    doublyTraversal(head);
    
    cout << "Reverse Traversal: " << endl;
    doublyTraversalRev(head);       // traverse in reverse direction
}