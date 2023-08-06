#include<iostream>
using namespace std;
 
struct Queue
{
    int cap;
    int *arr;
    int size;       // current size of queue
    int front;

    Queue(int capacity)
    {
        cap = capacity;
        size = 0;
        front = 0;
        arr = new int[cap];     // dynamic allocation
    }

    bool isFull()
    {
        return size == cap;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(int val)
    {
        if(isFull())
        {
            cout << "OverFlow!!!" << endl;
            return; 
        }

        int rear = getRear();
        rear = (rear + 1) % cap;
        arr[rear] = val;
        size++;
    }

    int dequeue()
    {
        if(isEmpty())
        {
            cout << "UnderFlow!!!" << endl;
            return -1;
        }

        int temp = arr[front];
        front = (front + 1) % cap;
        size--;

        return temp;
    }

    int getFront()
    {
        return front;
    }

    int getRear()
    {
        if(isEmpty())
        {
            cout << "Queue is empty!!" << endl;
            return -1;
        }

        return (front + size - 1) % cap;      
    }
};


int main()
{
    // using arrays all operations are O(1) except enqueue, but in circular arrya all operations are O(1)
    // we maintain front variable here, all other isfull size functions are same as normal array implementation

    Queue *q = new Queue(4);

    q->enqueue(12);
    q->enqueue(10);
    q->enqueue(30);
    q->enqueue(40);

    cout << "Front: " << q->getFront() << endl;
    cout << "Rear: " << q->getRear() << endl;
    cout << "Full?: " << q->isFull() << endl;

    cout << "Deleted: " << q->dequeue() << endl;
    cout << "Deleted: " << q->dequeue() << endl;
    cout << "Deleted: " << q->dequeue() << endl;

    q->enqueue(50);
    cout << "Rear: " << q->getRear() << endl;
    cout << "Front: " << q->getFront() << endl;

    cout << "Empty?: " << q->isEmpty() << endl;
}