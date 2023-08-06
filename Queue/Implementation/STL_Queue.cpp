#include<iostream>
#include<queue>
using namespace std;
 
int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    q.pop();

    cout << "last: " << q.back() << endl;
    cout << "First: " << q.front() << endl;

    cout << "Printing Queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    
    cout << "\nSize: " << q.size();
}