#include <iostream>

using namespace std;

struct stack
{
    int size;
    int top;
    int *arr;
};

int isempty(struct stack *ptr) // ptr pointer of type struct stack
{
    if (ptr->top == -1)
    {
        return 1;
    }
    
    return 0;
}

int main()
{
    // this also correct--->
    // struct stack s;
    // s.size = 4;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size * sizeof(int));


    // allocating dynamic memory using: new operatior(alternative to malloc)->
    // struct Stack *s = new struct Stack; 

    // allocating dynamic memory to the stack pointer s (necessory to store the size & top to the s)
    struct stack *s = (stack *)malloc(sizeof(stack));

    // struct stack *s;   // not work(coz we have to give dynamic allocation to s to store size & top in it)
    s->size = 4;
    s->top = -1;

    // allocating dynamic memory to the arr (of size-> maximum of array size)
    s->arr = (int *)malloc(s->size * sizeof(int));

    cout << "hii" << endl;
    if (isempty(s))
    {
        cout << "stack is empty!!" << endl;
    }
    else
        cout << "stack is not empty" << endl;

    return 0;
}