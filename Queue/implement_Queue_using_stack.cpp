#include<iostream>
#include<stack>
using namespace std;
 

// queue push will push new element in end of queue, but stack store new elem in top, 
// so here i store new element in bottom of stack 
// used insert at bottom problem as subroutine
void insertAtBottom(stack<int>& s, int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }

    int popped = s.top();
    s.pop();

    // recursive call
    insertAtBottom(s, x);

    // restore popped items
    s.push(popped);  
}
void push(stack<int>& s, int x)
{
    insertAtBottom(s, x);
}


// as we pushed new items at end of bottom of stack so for popping we simply pop elem at top of stack
// top item always first pushed in stack
int pop(stack<int>& s)
{
    if(s.empty())
        return -1;
    
    int popped = s.top();
    s.pop();

    return popped;
}

int main()
{
    // i will use only 1 stack here 
    stack<int> s;
    push(s, 12);
    push(s, 16);
    push(s, 134);

    // for queue first inserted should popped first
    
    cout << "Popped: " << pop(s) << endl;
    cout << "Popped: " << pop(s) << endl;
    cout << "Popped: " << pop(s) << endl;
    cout << "Popped: " << pop(s) << endl;
}