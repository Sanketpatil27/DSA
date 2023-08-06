#include<iostream>
using namespace std;
 
struct Queue
{
    int cap;
    int *arr;
    int size;       // current size of queue

    Queue(int capacity)
    {
        cap = capacity;
        size = 0;
        arr = new int[cap];     // dynamic allocation
    }

    void enqueue(int val)
    {
        if(size == cap)
        {
            cout << "OverFlow!!!" << endl;
            return; 
        }

        arr[size] = val;
        size++;
    }

    int dequeue()
    {
        if(size == 0)
        {
            cout << "UnderFlow!!!" << endl;
            return -1;
        }

        int temp = arr[0];

        // we have to delete first index value and shift other elements 1 index to left side
        for (int i = 0; i < size-1; i++)
            arr[i] = arr[i+1];
        
        size--;             // deleted front element
        return temp;
    }

    bool isFull()
    {
        return size == cap;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int getFront()
    {
        if(isEmpty())
        {
            cout << "Queue is empty!!" << endl;
            return -1;
        }

        return arr[0];
    }

    int getRear()
    {
        if(isEmpty())
        {
            cout << "Queue is empty!!" << endl;
            return -1;
        }

        return arr[size-1];      
    }

    int getSize()
    {
        return size;
    }
};


int main()
{
    // using arrays all operations are O(1) except enqueue, but in circular arrya all operations are O(1
    Queue *q = new Queue(2);

    q->enqueue(12);
    q->enqueue(10);

    cout << "Front: " << q->getFront() << endl;
    cout << "Rear: " << q->getRear() << endl;
    cout << "Size: " << q->getSize() << endl;
    cout << "Full?: " << q->isFull() << endl;

    cout << "Deleted: " << q->dequeue() << endl;
    cout << "Deleted: " << q->dequeue() << endl;
    cout << "Deleted: " << q->dequeue() << endl;

    cout << "Size: " << q->getSize() << endl;
    cout << "Empty?: " << q->isEmpty() << endl;
}