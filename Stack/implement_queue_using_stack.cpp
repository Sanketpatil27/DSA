https://leetcode.com/problems/implement-queue-using-stacks/editorial/

class MyQueue {
public:
    stack<int> s;       
    MyQueue() {
        
    }
    
    // when we push in stack elem goes on top of stack, but in queue it goes at last 
    // position so we have to push item at bottom of the stack, 
    // i have already done push at bottom while reversing stack problem
    void insertAtBottom(stack<int>& s, int x)
    {
        if(s.empty())
        {
            s.push(x);
            return;
        }

        int popped = s.top();
        s.pop();

        // recursive call for next elem
        insertAtBottom(s, x);

        // restore the popped elements
        s.push(popped);
    }
    
    void push(int x) {
        insertAtBottom(s, x);
    }
    
    int pop() {
        int popped = s.top();
        s.pop();
        return popped;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
