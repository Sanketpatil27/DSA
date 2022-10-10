#include <iostream>
using namespace std;


struct Node
{
    int data;
    struct Node *next; // to store the address of next nodes
};

int isEmpty(struct Node *top)
{
    if (top == NULL) // if top node is null means head data is null the stack is empty
    {
        return 1;
    }
    return 0;
}

int isFull(struct Node *top)
{
    struct Node *p = new struct Node; // this is like we creating head, second & third node(basically creating new node)
    if (p == NULL)                    // when stack of Node is pointing to null means node not created(means overflow)
    {
        return 1;
    }
    return 0;
}

struct Node *Push(struct Node *top, int data) // data to be loded in node
{
    if (isFull(top))
    {
        cout << "Stack is full, can't push " << data << endl;
    }
    else
    {
        struct Node *ptr = new struct Node; // this is like we creating head, second & third node
        ptr->data = data;
        ptr->next = top;                    // next will store the address of the top node
        cout << "Pushed: " << data << endl;
        return ptr;     // inserting ptr at index 0 (first node)
    }
}

// we created struct node for returning as node , not void or int
struct Node *Pop(struct Node *top)
{
    if (isEmpty(top))
    {
        cout << "Stack is Empty, cannot perform Pop operation!";
    }
    else
    {
        cout << "Poped: " << top->data << endl;
        top = top->next;            // changing top to the second node data
        return top;
    }
}

int main()
{
    // top node is always inserted on the heat of linked list
    
    // null coz it is refering the head node data, AND initialilly it is null(no any node in stack)
    struct Node *top = NULL;

    top = Push(top, 23); // new top will be set here
    top = Push(top, 34);
    top = Push(top, 8897);
    top = Pop(top);             // we have to update top everytime
    top = Pop(top);
    top = Pop(top);
    top = Pop(top);         // at this point top is pointing to NULL
}