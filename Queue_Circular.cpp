//  circular queue formula -> r = 1 size = 4
//  (r+1) % size = 2
//  r = 3, (r+1) % size = 0     // used this formula to circulate the array

#include <iostream>
#include <stdlib.h>
using namespace std;

struct circularqueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct circularqueue *q)
{
    if ((q->r + 1) % q->size == q->f) // it check in circular manner (circular increment)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct circularqueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int enqueue(struct circularqueue *q, int data)
{
    if (isFull(q))
    {
        cout << "Queue is full!" << endl;
    }
    else
    {
        cout << "equeued: " << data << endl;
        q->r = (q->r + 1) % q->size;        // called circular increment
        q->arr[q->r] = data;
    }
}

int dequeue (struct circularqueue *q) {
    if (isEmpty(q))
    {
        cout << "Queue is Empty!" << endl;
    }
    else
    {
        q->f = (q->f+1) % q->size;      // circular increment of front
        int dequed = q->arr[q->f];
        cout << "dequed: " << dequed << endl;
    }
}

int main()
{
    struct circularqueue *q = new struct circularqueue;
    q->size = 3;        // only 2 items can enque(in case size=3) coz 0th index is empty for front initial value
    q->f = q->r = 0;   // intitially front & rare are at 0th index (coz in circular queue at end rare can't come at -1 index)
    q->arr = (int *)malloc(q->size * sizeof(int));
    cout << isEmpty(q) << endl;
    cout << isFull(q) << endl;

    enqueue(q, 67);
    enqueue(q, 23);
    enqueue(q, 45);

    dequeue(q);
    dequeue(q);
    dequeue(q);

    enqueue(q, 75);


    cout << isEmpty(q) << endl;
    cout << isFull(q) << endl;
};