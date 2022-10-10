#include <iostream>
using namespace std;

bool flag = true;       // global variable, to set the pop is true or false

struct Stack
{
    int size;
    int top;
    char *arr; // to store elements in array dynamically
};

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1; // 1 means true
    }
    return 0;
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1; // 1 means true
    }
    return 0;
}

void Push(struct Stack *ptr, char data)
{
    if (isFull(ptr))
    {
        cout << "Stack Overflow, Can't Push In stack" << endl;
    }
    else
    {
        cout << "Pushed: " << data << endl;
        ptr->top++;                // first increase the top, coz initially it is -1, so can't push on -1
        ptr->arr[ptr->top] = data; // pushing element top of the array
    }
}

void Pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        // it means we are poping closing bracket, without opening bracket
        cout << "Stack OverFlow, Can't Pop" << endl;
        flag = false;
    }
    else
    {
        char poped = ptr->arr[ptr->top]; // to store the poping element, char coz its character brackets
        ptr->top--;
        cout << "Poped: " << poped << endl;
    }
}


int main()
{
    struct Stack *s = new struct Stack; // to store the size top arr dynamically in s pointer

    string problem = "(a*b2+3)";

    s->top = -1;                // initially top is -1
    s->size = problem.length(); // max elements in arr

    // to store array elements dynamically  (2 types)
    // s->arr = (char *)malloc(s->size * sizeof(char));
    s->arr = new char;

    for (int i = 0; i < s->size; i++)
    {
        if (problem[i] == '(')
        {
            Push(s, problem[i]);
        }

        if (problem[i] == ')')
        {
            Pop(s);
        }
    }
    // at this point is stack is empty, it means all pushed elems are poped, means perfect matching
    if (isEmpty(s) && flag)
    {
        cout << "Parenthesis are matching perfectly" << endl;
    }
    else
    {
        cout << "Parenthesis are not matching perfectly" << endl;
    }
}