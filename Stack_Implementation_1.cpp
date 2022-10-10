#include <iostream>
using namespace std;

struct Stack
{
    int size;    // maximum size of the array
    int top;     // top will point the topMost element of the stack
    int *arr;   // pointer to store the array elements dynamicly
};


int isEmpty(struct Stack *ptr)      // ptr pointer of type struct Stack
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)  // size -1 caz array index start from 0
    { 
        return 1;
    }
    return 0;
}

int main()
{
    // allocating dynamic memory using: new operatior(alternative to malloc)->
    // struct Stack *s = new struct Stack;      
    
    // allocating dynamic memory to the stack pointer s (necessory to store the size & top to the s)
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));;

    s->size = 4;
    s->top = -1;

    // allocating dynamic memory to the array (of size-> maximum of array size)
    s->arr = (int *)malloc(s->size * sizeof(int)); 


    if (isEmpty(s))
    {
        cout << "Stack is Empty!" << endl;
    }
    else
    {
        cout << "Stack is Not Empty!" << endl;
    }


    if (isFull(s))
    {
        cout << "Stack is Full!" << endl;
    }
    else
    {
        cout << "Stack is Not Full!" << endl;
    }
}