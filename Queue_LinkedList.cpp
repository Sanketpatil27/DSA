#include <iostream>
using namespace std;

// global variables
struct Node *f = NULL;     // to store the front node of queue
struct Node *r = NULL;     // to store the rare node of queue (Node type node)

struct Node
{
    int data;   // to store the linked list data
    struct Node *next;  // to store address of the next queue data item
};

void linkedListTraversal(struct Node *ptr) {
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

int isFull(struct Node *n)
{   // null means memory is full and new memory for node is not allocated
    return (n == NULL); // return 1 if condition is true, else 0
}

int isEmpty()
{
    return (f == NULL); // return 1 if condition is true, else 0
}

void enqueue(int val) // the return type of Node to return the node of Node
{
    struct Node *n = new struct Node();

    if (isFull(n))
    {
        cout << "Queue is Full!" << endl;
    }
    else
    {
        n->data = val;
        n->next = NULL;

        // this code runs when there is no any value in the queue, so we hava to point them to new first node
        // otherwise normal execution with rare incrementation
        if (f == NULL)
        {
            f = r = n;
        } 
        else
        {
            r->next = n;
            r = n;
        }
    }
};

int dequeue() {
    struct Node *ptr = f;

    if (isEmpty())
    {
        cout << "Queue is Empty can't dequeue" << endl;
    }
    else
    {
        f = f->next;

        int dequeued = ptr->data;
        free(ptr);

        cout << "Dequed: " << dequeued << endl;
    }   
}

int main()
{
    enqueue(23);
    enqueue(46);
    enqueue(53);
    linkedListTraversal(f);
    
    dequeue();
    dequeue();
    dequeue();
};