#include<iostream>
#include<deque>
using namespace std;

void pushMin(deque<int>& dq, int x)
{
    // we always push minimum at the front of deque
    dq.push_front(x);
}

void pushMax(deque<int>& dq, int x)
{
    // we always push maximum at the rear of deque
    dq.push_back(x);
}

int getMin(deque<int>& dq)
{
    if(dq.empty())
        return -1;

    // minimum resides on front of deque
    return dq.front();
}

int getMax(deque<int>& dq)
{
    if(dq.empty())
        return -1;

    // maximum resides on rear of deque
    return dq.back();
}

int extractMin(deque<int>& dq)
{
    if(dq.empty())
        return -1;

    // delete front (min always on front)
    int popped = dq.front();
    dq.pop_front();

    return popped;
}

int extractMax(deque<int>& dq)
{
    if(dq.empty())
        return -1;

    // delete rear (max always on rear)
    int popped = dq.back();
    dq.pop_back();

    return popped;
}

int main()
{
    deque<int> dq;

    pushMax(dq, 3);
    pushMin(dq, 2);
    pushMax(dq, 32);
    pushMin(dq, 1);

    cout << "Deque items: ";
    for (auto &&i : dq)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Extract Min: " << extractMin(dq) << endl;
    cout << "Extract Max: " << extractMax(dq) << endl;
}