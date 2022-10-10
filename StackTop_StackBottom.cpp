#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *ptr) // ptr pointer of type struct Stack
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1) // size -1 caz array index start from 0
    {
        return 1;
    }
    return 0;
}

void Push(struct Stack *ptr, int data)
{
    if (isFull(ptr))
    {
        cout << "------Stack OverFlow------" << endl;
        cout << "Stack is Full, can't push " << data << endl;
    }
    else
    {
        cout << "Pushed: " << data << endl;
        ptr->top++;                // increment first coz -1 will become 0 at sarting
        ptr->arr[ptr->top] = data; // it is array so we have to give index
    }
}

void Pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "------Stack Underflow------" << endl;
        cout << "Stack is Empty, can't pop any more" << endl;
    }
    else
    {
        int popped = ptr->arr[ptr->top];
        ptr->top--;
        cout << "Popped: " << popped << endl;
    }
}

int Top(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        return -1;
    }
    return ptr->arr[ptr->top];
}

int Bottom(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        return -1;
    }
    return ptr->arr[0];
}

int main()
{
    // struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    struct Stack *s = new struct Stack;

    s->size = 4;
    s->top = -1;
    s->arr = new int();     // dynamically memory allocated for array elements

    cout << "Stack is created successfully\n";

    Push(s, 9);
    Push(s, 92);
    Push(s, 9223);
    Push(s, 23);
    Push(s, 789); // this will not insert in stack(overflow on size)

    Pop(s); // top value is poped always
    Pop(s);
    Pop(s);
    Pop(s);
    Pop(s); // stack will be empty at this point (top == -1)

    cout << "Top of stack: " << Top(s) << endl;
    cout << "Bottom of stack: " << Bottom(s) << endl;
}