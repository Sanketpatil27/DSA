#include <iostream>
#include <string.h> // include to use strlen(), to count character in pointer
using namespace std;

struct Stack
{
    int size;       // to check the end of the expression
    int top;        // to check the element on top
    char *arr;      // to store expression characters
};

int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}


char stackTop(struct Stack *ptr)    // it will only return the top character of the stack
{
    return ptr->arr[ptr->top]; 
}

void Push(struct Stack *ptr, char data)
{
    if (isFull(ptr))
    {
        cout << "Stack OverFlow!" << endl;
    }
    else
    {
        ptr->top++;       // first increase top coz it's initialize value is -1, and we can't push at -1 index
        ptr->arr[ptr->top] = data;
        cout << "Pushed: " << data << endl;
    }
}

char Pop(struct Stack *ptr)     // return type is char coz we are returning character
{
    if (isEmpty(ptr))
    {
        cout << "Stack UnderFlow!" << endl;
        return -1;
    }
    else
    {
        char popped = stackTop(ptr);      // always popping elem will be on top
        ptr->top--;
        cout << "Popped: " << popped << endl;

        return popped;
    }
}


int isOperator(char c)
{
    if (c == '*' || c == '/' || c == '-' || c == '+')
    {
        return 1;
    }
    return 0;
}

int prec(char oprt) // this will return the precedance of the operators
{
    if (oprt == '*' || oprt == '/')
    {
        return 3; // highest precedance
    }
    else if (oprt == '+' || oprt == '-')
    {
        return 2; // low precedance (asumed 2)
    }
    else
    {
        return 0;
    }
    
}

char *infixToPostfix(char *infix)        // return type char pointer, to return the postfix pointer
{
    struct Stack *s = new struct Stack; // without object creation we only store address in operator
    s->top = -1;                                     // initially stack is empty
    s->size = strlen(infix);                         // it stores maximum size of expression pointer
    s->arr = (char *)malloc(s->size * sizeof(char)); // dynamic memory allocation to the array

    // pointer to store converted conversion, strlen() +1 coz last elem in char pointer is '\0' wich is not considered in strlen() method of infix expression
    char *postfix = (char *)malloc((s->size+1) * sizeof(char)); // size + 1 coz we have to count null('\0') at last also

    int i = 0; // to iterate the infix expression
    int j = 0; // to fill the postfix expression

    while (infix[i] != '\0')        // means loop till not end of the expression
    {
        if (isOperator(infix[i]))  // under this all operations are checked only for if there is operator
        {
            if (isEmpty(s)) // if stack is empty, then we will directly push, otherwise precedance wise
            {
                Push(s, infix[i]);
                i++; //  i would be increasing after each push operation to iterator next char
            }
            else  // if stack is not empty 
            {
                // if precedance of current pushing operator is strictly high than stackTop operator, then it push, otherwise pop the top operator
                if (prec(infix[i]) > prec(stackTop(s)))
                {
                    Push(s, infix[i]);
                    i++;
                }
                else        // if current operator precedance is low then pop
                {
                    postfix[j] = Pop(s); // popping operator will be adding in postfix expression
                    j++;
                    // this time we not increasing i, coz to check the next operator in top, then again comparison then push, and increase i
                }
            }
        }
        else        // then we check if there is no operator, means check for operands
        {
            postfix[j] = infix[i];  // we directly push the operands in infix to the postfix expression
            j++;        // to locate next pushing index
            i++;        // to iterate next char in infix expression
        }
    }

    // at end of infix expression we have to pop all remaining stack operators in postfix and also at end, '\0' should be added to postfix expression
    while (!isEmpty(s))
    {
        postfix[j] = Pop(s);        // we were poping till stack becomes -1
        j++;                        // to update index no.
    }
    postfix[j] = '\0';      // this is added at end of converted expression

    return postfix;
}


int main()
{
    char *infix = "x-y*k+m"; // automatically add '\0' at end

    cout << "Infix: " << infix << "\nPostfix: " << infixToPostfix(infix) << endl;
}