#include <iostream>
using namespace std;

struct Deque
{
    // front always remain on 0th index
    // rear always remain on size-1 th index, so don't need these 2 extra variables

    int *arr;  // dynamic size array
    int size;  // size of Deque
    int cap;   // capacity of Deque

    Deque(int capacity)
    {
        size = 0;
        cap = capacity;
        arr = new int[cap];
    }

    bool isFull()
    {
        return size == cap;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void insertFront(int x)
    {
        if (isFull())
        {
            cout << "Deque OverFlow!!!" << endl;
            return;
        }

        // we have to insert front so make empty space in 0th index shift all elems right side by 1 index
        // last element is on (size-1) index, so no-one at size index
        // i >= 1 coz there is nothing in left of 0th index
        for (int i = size; i >= 1; i--)
            arr[i] = arr[i - 1]; // shift to right

        arr[0] = x; // now after shifting push x on front of Deque
        size++;     // increment size by 1 after inserting
    }

    void insertRear(int x)
    {
        if (isFull())
        {
            cout << "Deque OverFlow!!!" << endl;
            return;
        }

        // we simply add x on size'th index
        arr[size] = x;
        size++; // increment size by 1 after inserting
    }

    int deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque UnderFlow!!!" << endl;
            return -1;
        }
        
        int deleted = arr[0];

        // we have to delete front so shift other elements 1 index on left
        for (int i = 0; i < size - 1; i++)
            arr[i] = arr[i + 1]; // shift to right

        size--; // decrement size by 1 after deleting front
        return deleted;
    }

    int deleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque UnderFlow!!!" << endl;
            return -1;
        }

        int deleted = arr[size-1];
        size--;     // we just decrement size to delete rear

        return deleted;
    }

    void printDQ()
    {
        cout << "Printing Deque: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        
        return arr[0];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        
        return arr[size-1];
    }
};

int main()
{
    Deque *dq = new Deque(4);

    dq->insertFront(10);
    dq->insertRear(20);
    dq->insertFront(30);
    dq->insertRear(50);
    dq->insertRear(80);         // overflow here size becomes > capacity(4)

    dq->printDQ();

    cout << "Front: " << dq->getFront() << endl;;
    cout << "Rear: " << dq->getRear() << endl;
    cout << "Deleted Front: " << dq->deleteFront() << endl;
    cout << "Deleted Rear:  " << dq->deleteRear() << endl;
    cout << "Front: " << dq->getFront() << endl;
    cout << "Rear: " << dq->getRear() << endl;
    
    dq->printDQ();
}