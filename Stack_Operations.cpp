#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *arr; // pointer to store the array elements dynamically
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
        ptr->top++;                     // increment first coz -1 will become 0 at sarting
        ptr->arr[ptr->top] = data;     // it is array so we have to give index
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

int main()
{
    struct Stack *s = new struct Stack;

    s->size = 4;
    s->top = -1;
    // allocating dynamic memory to the arr of size s->size
    s->arr = (int *)malloc(s->size * sizeof(int));
    
    cout << "Stack is created successfully\n";

    Push(s, 9);
    Push(s, 92);
    Push(s, 9223);
    Push(s, 23);
    Push(s, 789);           // this will not insert in stack(overflow on size)

    Pop(s);                 // top value is poped always
    Pop(s);     
    Pop(s);     
    Pop(s);     
    Pop(s);                 // stack will be empty at this point (top == -1)
}