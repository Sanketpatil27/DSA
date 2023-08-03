#include<iostream>
#include<stack>
using namespace std;
 
void insertAtBottom(stack<int>& st, int num)
{
    if(st.empty())
    {
        st.push(num);
        return;
    }

    // store top for restoring
    int res = st.top(); 
    st.pop();

    // recursive call to reach bottom
    insertAtBottom(st, num);

    // restore the popped items
    st.push(res);
}


void reverseStack(stack<int> &stack) {
    if(stack.empty())
        return;

    // keep aside the top element to store it again & at bottom of stack 
    int num = stack.top();
    stack.pop();

    // reverse the remaining stack 
    reverseStack(stack);

    // after upper call, stack will be empty as we poped every top element
    // now push the stored element at bottom
    insertAtBottom(stack, num);
}

int main()
{
    // Algorithm: 
    // ReverseStack(stack)
    //      If the stack is empty, then return
    //      Pop the top element from the stack as top
    //      Reverse the remaining elements in the stack, call reverseStack(stack) method
    //      Insert the top element to the bottom of the stack, call InsertAtBottom(stack, top) method
    // InsertAtBottom(stack, ele)
    //      If the stack is empty, push ele to stack, return
    //      Pop the top element from the stack as top
    //      Insert the ele to the bottom of the stack, call InsertAtBottom(stack, ele) method
    //      Push top to the stack.
    // Time Complexity
    // O(N^2), where ‘N’ is the total number of elements in the given stack.

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    // after pushing stack looks from top: 5 4 3 2 1
    reverseStack(st);
    cout << "reversed stack: ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}