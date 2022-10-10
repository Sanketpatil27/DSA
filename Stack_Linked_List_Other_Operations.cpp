#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next; // store the address of the nexs node
};

int isFull(struct Node *top)
{
    // when we creating new node, if it not created then it point to null means stack is full
    struct Node *ptr = new struct Node;
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

struct Node *Push(struct Node *top, int data)
{
    if (isFull(top))
    {
        cout << "Can't Push " << data << endl;
    }
    else
    {
        struct Node *ptr = new struct Node; //  pushing new node
        ptr->data = data;
        ptr->next = top;
        cout << "Pushed: " << data << endl;
        return ptr;
    }
}

int stackTop(struct Node *top)
{
    return top->data;
}

int stackBottom(struct Node *top)
{
    while (top->next != NULL)
    {
        top = top->next;
    }
    // at this point ptr is on last node, coz this next node is null, so don't go in while loop
    return top->data;
}

void stackLinkedTraversal(struct Node *ptr) {
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

int Peek(struct Node *top, int position)
{
    int i = 0;
    while (i < position-1 && top != NULL)
    {
        top = top->next;
        i++;
    }
    // at this point top pointing to positional node
    if (top != NULL)
    {
        return top->data;
    }
    else
    {
        return -1;
    }
}

int main()
{
    struct Node *top = NULL;

    top = Push(top, 23);
    top = Push(top, 2456);
    top = Push(top, 453);
    top = Push(top, 9856);

    cout << "Top Node Of the Stack: " << stackTop(top) << endl;
    cout << "Bottom Node Of the Stack: " << stackBottom(top) << endl;
    stackLinkedTraversal(top);
    cout << "Node At Position 3: " << Peek(top, 3) << endl;
}