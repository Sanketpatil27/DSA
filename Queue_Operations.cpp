#include <iostream>
using namespace std;

struct queue
{
    int size;
    int f;              // to store front elements
    int r;              // to store the rare elements
    int *arr;           // to store the elemenets of array
};

int isFull(struct queue *ptr) {
    return (ptr->r == ptr->size-1);      // -1 coz rare starts from 0, intitially it is -1
}

int isEmpty(struct queue *ptr) {
    return (ptr->r == ptr->f);      // it will return true, if the condition is true, otherwise flase
}

void enqueue(struct queue *ptr, int data) {
    if (isFull(ptr))
    {
        cout << "Queue is full!" << endl;
    }
    else
    {
        ptr->r++;
        ptr->arr[ptr->r] = data;
        cout << "Enqueued: " << data << endl;
    }    
}

void dequeue(struct queue *ptr) {
    if (isEmpty(ptr))
    {
        cout << "Queue is Empty!" << endl;
    }
    else
    {
        ptr->f++;       // increasing the front of the queue to to dequeue it
        int dequed = ptr->arr[ptr->f];        // to store the first element in the queue
        cout << "Dequed: " << dequed << endl;
    }    
}

int main()
{
    struct queue *q = new struct queue;
    q->size = 2;
    q->f = q->r = -1;                // initially both rare and front are equal to -1 index
    q->arr = (int *)malloc(q->size * sizeof(int));

    cout << "Empty: " << isEmpty(q) << endl;
    cout << "Full: " << isFull(q) << endl;

    enqueue(q, 10);
    enqueue(q, 30);
    enqueue(q, 20);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    // enqueue(q, 44);      // can't enqueue also after dequeing all elements thats resolve in circular queue

    // cout << "Empty: " << isEmpty(q) << endl;             
    // cout << "Full: " << isFull(q) << endl;    // this is bug(show full everytime when r is constant, at time of dequeing)
}