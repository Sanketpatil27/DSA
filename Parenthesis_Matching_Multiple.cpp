#include <iostream>
using namespace std;


struct Stack
{
    int size;
    int top;       
    char *arr;
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
        return 1;
    }
    return 0;
}

void Push(struct Stack *ptr, char data)
{
    if (isFull(ptr))
    {
        cout << "Can't Push" << endl;
    }
    else
    {
        cout << "Pushed: " << data << endl;
        ptr->top++;
        ptr->arr[ptr->top] = data; // pushing data on the top of the stack
    }
}

char Pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Can't Pop" << endl;
        return -1;      
    }
    else
    {
        char popped = ptr->arr[ptr->top];
        cout << "Popped: " << popped << endl;
        ptr->top--;
        return popped;
    }
}

int match(char top, char popping) {     // poping is a elem which we want to pop
    if (top == '{' && popping == '}') {
        return 1;
    }
    if (top == '(' && popping == ')') {
        return 1;
    }
    if (top == '[' && popping == ']') {
        return 1;
    }
    return 0;
}

int isMatching(struct Stack *s, string exp)
{
    for (int i = 0; i < s->size; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            Push(s, exp[i]);
        }

        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty(s)) // means if top parenthesis is not same as exp[i](poping) parenthesis, then false
            {
                return 0; // means false, we can't pop when stack is empty
            }
            else
            {
                char top = s->arr[s->top];     // poped will sote the top element
                // elements will only pop if matching is true, otherwise direct return false, without reason
                if (match(top, exp[i]))        // exp[i] is a char which we want to pop, and top is the popping char
                {
                    Pop(s);
                }
                else
                {
                    return 0;// means top parenthesis and the parenthesis we are going to pop is not same
                }
            }
        }
    }
    // at last we have tocheck this coz at last after pushing opening parenthesis, function don't go in the else block, to check stack is empty or not
    if (isEmpty(s))
    {
        return 1; 
    }
    else
    {
        return 0;  // means all operations not performed successfully(stack is not empty)
    }
}

int main()
{
    struct Stack *s = new struct Stack;

    string exp = "(){[]}()}879";
    s->top = -1;
    // cout << s->top;
    s->size = exp.length();
    s->arr = (char *)malloc(s->size * sizeof(char));

    if (isMatching(s, exp))
    {
        cout << "Parenthesis Matching Perfectly" << endl;
    }
    else
    {
        cout << "Parenthesis Not Matching Perfectly" << endl;
    }
}