#include<iostream>
using namespace std;
 
struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};


struct Queue
{
    Node *front;
    Node *rear;

    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int val)
    {
        Node *temp = new Node(val);

        // list is empty then set front & rear both
        if(front == NULL)
        {
            front = rear = temp;
            return;
        }
        
        rear->next = temp;
        rear = temp;              // move rear to new rear
    }

    int dequeue()
    {
        if(front == NULL)
            return -1;

        // remove from front
        Node *temp = front;
        front = front->next;
        
        // if list becomes empty when we delete last remaining node make rear also NULL
        if(front == NULL)
            rear = NULL;

        // delete temp from memory
        int val = temp->data;
        delete temp;

        return val;
    }

    int getFront()
    {
        return front->data;
    }

    int getRear()
    {
        return rear->data;      
    }
};


int main()
{
    // using arrays all operations are O(1) except enqueue, but in circular arrya all operations are O(1)
    // we maintain front variable here, all other isfull size functions are same as normal array implementation

    Queue *q = new Queue();

    q->enqueue(12);
    q->enqueue(10);
    q->enqueue(30);
    q->enqueue(40);

    cout << "Front: " << q->getFront() << endl;
    cout << "Rear: " << q->getRear() << endl;

    cout << "Deleted: " << q->dequeue() << endl;
    cout << "Deleted: " << q->dequeue() << endl;
    cout << "Deleted: " << q->dequeue() << endl;

    q->enqueue(50);
    cout << "Rear: " << q->getRear() << endl;
    cout << "Front: " << q->getFront() << endl;
}