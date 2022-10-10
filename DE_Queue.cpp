// Double-Ended Queue (Not work on First In First Out)

#include<iostream>
using namespace std;

struct DEQueue
{
    int size;
    int f;              // to point the front element
    int r;              // to point the rare element
    int *arr;
};

int isFull(struct DEQueue *q) {
    return (q->r == q->size-1);    
}

int isEmpty(struct DEQueue *q) {
    return (q->f == q->r);    
}

void enqueueR(struct DEQueue *q, int data) {    // enqueue from rare(normal)
    if (isFull(q))
    {
        cout << "Queue Overflow!" << endl;
    }
    else
    {
        q->r++;                 // first we have to increase, coz initially it is -1
        q->arr[q->r] = data;
        cout << "Enqueued Rare: " << data << endl;
    }
}

void enqueueF(struct DEQueue *q, int data) {    // enqueue from front(double-ended)
    if (q->f == -1)     // this means queue is empty and can't insert from front
    {
        cout << "Can't Insert from front!" << endl;
    }
    else
    {
        q->arr[q->f] = data;
        // we have to decrease after  up code(data allocate), coz f position before insertion from front is on the deleted element, so we have to reallocate this data to new inserting data
        q->f--;                 
        cout << "Enqueued Front: " << data << endl;
    }
}

int dequeueF(struct DEQueue *q) {       // dequeue from front(normal)
    if (isEmpty(q))
    {
        cout << "Queue is Empty!" << endl;
        return -1;
    }
    else
    {
        q->f++;         // first increase, coz initially it is -1
        cout << "Dequeued Front: " << q->arr[q->f] << endl;
        return q->arr[q->f];
    }
}

void dequeueR(struct DEQueue *q) {       // dequeue from Rare(double-ended))
    if (q->r == -1)                     // it check's that r is not on the initial stage empty
    {
        cout << "Queue is Empty!" << endl;
    }
    else
    {
        cout << "Dequeued Rare: " << q->arr[q->r] << endl;
        // we have to decrese after  up code(data return), coz r position before deleting from rare is on that deleting element
        q->r--;         
    }
}

int main()
{
    struct DEQueue *q = new struct DEQueue;
    q->f = q->r = -1;
    q->size = 4;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueueR(q, 1);
    enqueueR(q, 2);
    dequeueF(q);
    enqueueR(q, 3);
    enqueueF(q, 4);         // this will be added in front of the queue

    dequeueF(q);
    dequeueR(q);
    dequeueR(q);
    dequeueR(q);
};