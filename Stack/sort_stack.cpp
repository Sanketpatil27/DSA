#include<iostream>
#include<stack>
using namespace std;
 

void sortedInsert(stack<int>& st, int num)
{
	// base case
	// for pushing in sorted order we have to ensure if num is > top of stack
	if(st.empty() || num > st.top())
	{
		st.push(num);
		return;
	}

	// if current top not < num then keep it aside till we got lesser top than num
	int n = st.top();
	st.pop();

	// recursive call for next top
	sortedInsert(st, num);

	// restore the popped elements
	st.push(n);
}

void sortStack(stack<int> &stack)
{
	// base case
	if(stack.empty())
		return;

	// keep top aside for restoring sorted wise
	int num = stack.top();
	stack.pop();

	sortStack(stack);

	// while returning push or restore the top that we keep aside, sorted wise
	sortedInsert(stack, num);
}

int main()
{
    stack<int> st;

    st.push(8);
    st.push(-2);
    st.push(7);
    st.push(-1);
    // after pushing stack looks from top: -1 7 -2 8

    sortStack(st);
    cout << "stack after sorting: ";
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}