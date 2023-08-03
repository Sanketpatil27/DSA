#include<iostream>
using namespace std;
 
 // we will give 1st array start to stack 1 & 2nd stack access array from end of the array
struct TwoStacks
{    
    int top1;               // for 1st stack
    int top2;               // for 2nd stack
    int size;
    int *arr;

    TwoStacks(int len)
    {
        top1 = -1;
        top2 = len;        // 2nd stack access from end of array so first top2 is beyond last index
        size = len;
        arr = new int[size];
    }

    // for stack1
    void push1(int val)
    {
        // this means if our array one end reaches stack 2 end then its overlflow
        if(top1 == top2-1)  
        {
            cout << "Stack1 is Full!!" << endl;
            return;         // stopped here to don't go further
        }

        cout << "pushed value in stack1: "<< val << endl;
        top1++;             // top1 is index initially its -1 so we first have to increase it
        arr[top1] = val;
    }

    int pop1()
    {
        if(top1 == -1)
        {
            cout << "Can't pop stack1 is empty!!" << endl;
            return -1;
        }

        int res = arr[top1];
        top1--;                 // we removed element so decrease top1
        return res;
    }

    int peek1()
    {
        if(top1 == -1)
        {
            cout << "Stack1 is empty!!!" << endl;
            return -1;
        }

        return arr[top1];
    }

    int size1()
    {
        return top1+1;          // +1 coz top1 represents index number, so size is +1
    }
    
    bool isEmpty1()
    {
        return top1 == -1;      // when stack1 is empty then top1 is -1
    }

    // *** for stack2 *** 
    void push2(int val)
    {
        // this means if our array one end reaches stack 1 end then its overlflow
        if(top2 == top1+1)  
        {
            cout << "Stack2 is Full!!" << endl;
            return;         // we have to stop here, function cant access further values
        }

        cout << "pushed value in stack2: "<< val << endl;
        top2--;             // top2 is index initially it is on size (beyoun last index)
        arr[top2] = val;
    }

    int pop2()
    {
        // when stack2 empty top2 is beyong last index
        if(top2 == size)
        {
            cout << "Can't pop, stack2 is empty!!" << endl;
            return -1;
        }

        int res = arr[top2];
        top2++;                 // we removed element so increase top2 (stack2 starts from end)
        return res;
    }

    int peek2()
    {
        if(top2 == size)
        {
            cout << "Stack2 is empty!!!" << endl;
            return -1;
        }

        return arr[top2];
    }

    int size2()
    {
        return size - top2;          // coz top2 starts from last index
    }
    
    bool isEmpty2()
    {
        return top2 == size;      // when stack2 is empty then top2 on beyond last index, means on size
    }
};


int main()
{
    TwoStacks s(10);        // 10 is total size array

    s.push1(1);
    s.push2(2);

    cout << "peak of stack 1: " << s.peek1() << endl;
    cout << "peek of stack 2: " << s.peek2() << endl;

    cout << "poped value from stack 1: " << s.pop1() << endl;
    cout << "poped value from stack 1: " << s.pop1() << endl;
    cout << "poped value from stack 2: " << s.pop2() << endl;

    cout << "is stack1 empty?: " << s.isEmpty1() << endl;
    cout << "is stack2 empty?: " << s.isEmpty2() << endl;

    cout << "size of stack1: " << s.size1() << endl;
    cout << "size of stack2: " << s.size2() << endl;
}