#include<iostream>
#include<deque>
using namespace std;
 
int main()
{
    // all operations of Deque are with O(1) time
    deque<int> dq = {1, 2, 3, 4, 5, 6};

    dq.push_front(0);
    dq.push_back(7);

    cout << "deque elements: ";
    for (int i : dq)
        cout << i << ' ';

    cout << endl;

    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;
    
    // gives the iterator to first element
    auto it = dq.begin();   
    it++;           // moves to second element

    // it inserts the element before the iterator
    dq.insert(it, 20);

    dq.pop_front();      // removes front elem
    dq.pop_back();      // removes last elem
    
    cout << "After removing front & back: " << endl;
    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;
    
    cout << "Size: " << dq.size() << endl;
}