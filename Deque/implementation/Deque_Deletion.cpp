#include<iostream>
#include<deque>
using namespace std;
 
//Function to erase the element from specified position X in deque.
void eraseAt(deque <int> &deq, int X)
{
    // erase function deletes element at specified iterator
    deq.erase(deq.begin()+X);
}

//Function to erase the elements in range start (inclusive), end (exclusive).
void eraseInRange(deque<int> &deq, int start, int end)
{
    // erase function also deletes element at specified iterator ranges
    deq.erase(deq.begin() + start, deq.begin() + end);
}

//Function to erase all the elements in the deque.
void eraseAll(deque<int> &deq)
{
   deq.clear();
}

void printDQ(deque<int> dq)
{
    for (auto i : dq)
        cout << i << ' ';

    cout << endl;
}

int main()
{
    deque<int> dq = {1, 2, 3, 4, 5, 6, 7};

    cout << "Original DQ: ";
    printDQ(dq);

    cout << "DQ after deleting index 2: ";
    eraseAt(dq, 2);                 // providing index
    printDQ(dq);

    cout << "DQ after deleting index 3 to 5: ";
    eraseInRange(dq, 3, 5);         // ending is excluding
    printDQ(dq);

    cout << "DQ after deleting all elements: ";
    eraseAll(dq);
    printDQ(dq);
}