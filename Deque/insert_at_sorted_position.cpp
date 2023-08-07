#include<iostream>
#include<deque>
using namespace std;
 
void printDQ(deque<int> dq)
{
    for (auto i : dq)
        cout << i << ' ';

    cout << endl;
}

void sortedInsert(deque<int>& dq, int x)
{
    auto itr = dq.begin();
    for(itr = dq.begin(); itr != dq.end(); ++itr)
        if(*itr > x)
            break;

    // insert function insert elem before iterator
    dq.insert(itr, x);
}

int main()
{
    deque<int> dq = {22, 33, 44, 55};
    int x = 64;

    cout << "Before insertion: ";
    printDQ(dq);

    cout << "After insertion: ";
    sortedInsert(dq, x);
    printDQ(dq);
}