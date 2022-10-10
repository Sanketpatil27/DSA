#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *arr; // pointer to store the array elements dynamically
};

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

void Peek(struct Stack *ptr, int i)
{
    if (i <= 0 || i > ptr->top+1)           // top + 1 coz top starts with 0
    {
        cout << "Can't Perform Peek Operation!\n";
    }
    else
    {
        // formula to perform peek operation: ptr->top - i + 1   
        cout << "Value At position " << i << ": " << ptr->arr[ptr->top - i + 1] << endl;
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
    Push(s, 789); // this will not insert in stack(overflow on size)

    Peek(s, 3); // first is pointer second is position that we want
}