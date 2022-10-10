#include <iostream>

using namespace std;

struct stack
{
    int size;
    int top;
    int *arr;
};


int isempty(struct stack ptr)       // variable of type struct stack
{
    if (ptr.top == -1)
    {
        return 1;
    }
    return 0; 
}

int main()
{
    struct stack s;
    s.size = 4;
    s.top = -1;
    s.arr = (int *) malloc(s.size * sizeof(int));
    
    cout << "hii" << endl;
    if (isempty(s))
    {
        cout <<"stack is empty!!" << endl;
    }
    else 
    cout <<"stack is not empty" << endl;
    

    return 0;
}