#include<iostream>
#include<queue>
#include<stack>
using namespace std;
 
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> st;
    queue<int> ans;

    // push first k elems in stack
    while(k--)
    {
        st.push(q.front());
        q.pop();
    }

    // now push stack elems in ans
    while(!st.empty())
    {
        ans.push(st.top());
        st.pop();
    }
    
    // now push remaining elems of q in ans
    while(!q.empty())
    {
        ans.push(q.front());
        q.pop();
    }
    
    return ans;
}

int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    int k = 3;

    q = modifyQueue(q, k);

    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}