#include<iostream>
#include<stack>
using namespace std;
 
void solve(stack<int>& s, int size, int cnt)
{
    if(cnt == size/2)
    {
        s.pop();            // this will not be restored
        return;
    }


    int res = s.top();      // has to be restore     
    s.pop();                // delete items till middle
    cnt++;
    solve(s, size, cnt);
    s.push(res);            // restore the elements
    
}

void deleteMid(stack<int>&s, int sizeOfStack)
{
    int cnt = 0;            // to track middle element
    solve(s, sizeOfStack, cnt);
}

int main()
{
//     Given a stack, delete the middle element of the stack without using any additional data structure.
//     Middle element:- floor((size_of_stack+1)/2) (1-based indexing) from bottom of the stack.
//     Note: The output shown by the compiler is the stack from top to bottom.


    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // st.push(5);


    deleteMid(st, st.size());

    cout << "\nafter deleting middle of stack: ";
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}