#include<iostream>
using namespace std;
 
struct KQueues
{
    int *arr;           // array to store n queue's 
    int *next;          // to store next free block in available array
    int *front;         // to store front elem index of every k queues
    int *rear;          // to store rear elem index of every k queues
    int freeSpot;       // free block to push current element
    int n;              // size of the array 

    KQueues(int size, int k)
    {
        n = size;
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        freeSpot = 0;               // initially free spot should be 0 for first insertion

        // fill next array with next free blocks for every i
        for(int i = 0; i < n-1; i++)
            next[i] = i+1;          // ex: 0th index store next free block as index 1

        next[n-1] = -1;          // for last index there is no free block available further so -1 should be there


        // fill front & rear of every queue with -1 initially
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }
    }


    // push value in qn'th queue 
    void enqueue(int val, int qn)
    {
        // if no space is available to push current value
        if(freeSpot == -1)
            return;
        
        // step1: get the free spot to store value
        int ind = freeSpot;
        
        // step2: update freeSpot with next free block
        freeSpot = next[ind];         // next[i] contains next free block for ith index

        // step3: update front for the current Queue
        // if current elem is first elem in current queue then update front
        if(front[qn-1] == -1)        
            front[qn-1] = ind;       // 0 based indexing

        // link previous rear with current new rear:
        // if it's not first elem, then connect m's rear with current new rear
        // previously rear[qn-1] will be holding the last index for the m queue 
        // so on this last index index(rear[qn-1]) we store the current index, as current index is new rear for current queue
        // we can keep track of this using next array.
        // ex: [1, 2]    first elem is of q1, second of q2, rear[q1] = 0, rear[q2] = 1
        // now we want to store new element 3 in q1 again, so array become: [1, 2, 3]
        // so previously p1's rear(rear[qn-1]) is on 0th index, now after inserting 3 in q1 our new rear become 2nd index
        // we can easily store it on rear[qn-1] = 2 index, 
        // but we also have to connect it with q1's previous rear so, there's no issue while traversing every queue's elements 
        // so using next array we can get next element of current queue
        else    
            next[rear[qn-1]] = ind;

        // step4: update next[ind] to -1 as we used this block, so its no longer free
        next[ind] = -1;

        // step5: update rear
        rear[qn-1] = ind;
        
        // step6: push value in array
        arr[ind] = val;
    }


    int dequeue(int qn)
    {
        // if current queue's front is -1 then queue is empty
        if(front[qn-1] == -1)        
        {
            cout << "Queue UnderFlow!!!" << endl;
            return -1;
        }

        // find index of front of queue to pop
        int ind = front[qn-1];

        // now we popped front, so move front to next element in queue
        front[qn-1] = next[ind];            // that's why we link every new elem with previous rear of queue

        // make current index as freeSpot coz we deleted this  element
        next[ind] = freeSpot;       // link current free block with next freeSpot
        freeSpot = ind;             // bring freeSpot on current index

        return arr[ind];
    }
};


int main()
{
    KQueues *q = new KQueues(10, 3);

    q->enqueue(10, 3);
    q->enqueue(10, 1);
    q->enqueue(15, 1);
    q->enqueue(20, 2);
    q->enqueue(25, 1);

    cout << q->dequeue(1) << endl;
    cout << q->dequeue(2) << endl;
    cout << q->dequeue(1) << endl;
    cout << q->dequeue(1) << endl;
    cout << q->dequeue(1) << endl;
}